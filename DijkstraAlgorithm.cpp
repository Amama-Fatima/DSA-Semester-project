#include <iostream>
#include <limits>
#include <vector>
#include "GraphAdj.h"
#include "Book.h"

using namespace std;

extern GraphAdj bookAdjGraph;
extern Book* bookListHead; // Global head pointer for the book list

// Function to find the book ID by name
int findBookIdByName(const string& bookName) {
    Book* temp = bookListHead;
    while (temp != nullptr) {
        if (temp->title == bookName) {
            return temp->id;
        }
        temp = temp->right;
    }
    return -1; // Not found
}

// Modified Dijkstra's algorithm using direct access to the adjacency matrix
vector<int> dijkstra(int src) {
    int numVertices = bookAdjGraph.numVertices; // Assuming numVertices is accessible
    vector<int> dist(numVertices, numeric_limits<int>::max());
    vector<bool> sptSet(numVertices, false);

    dist[src] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = -1;
        int minDistance = numeric_limits<int>::max();
        for (int v = 0; v < numVertices; v++) {
            if (!sptSet[v] && dist[v] <= minDistance) {
                minDistance = dist[v], u = v;
            }
        }

        sptSet[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (!sptSet[v] && bookAdjGraph.adjacencyMatrix[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + bookAdjGraph.adjacencyMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + bookAdjGraph.adjacencyMatrix[u][v];
            }
        }
    }
    return dist;
}


// Function to recommend books
void recommendBooks(const string& bookName) {
    int bookId = findBookIdByName(bookName);
    if (bookId == -1) {
        cout << "Book not found." << endl;
        return;
    }
    // Adjust for 0-based indexing if necessary
    vector<int> distances = dijkstra(bookId - 1); // Assuming book IDs start from 1

    cout << "Books recommended based on " << bookName << ":" << endl;

    for (int i = 0; i < distances.size(); ++i) {
        if (i != bookId - 1 && distances[i] != numeric_limits<int>::max()) {
            // Iterate over the book list to find the book with ID i + 1
            Book* temp = bookListHead;
            while (temp != nullptr) {
                if (temp->id == i + 1) {
                    cout << "Book: " << temp->title << " (Distance: " << distances[i] << ")" << endl;
                    break;
                }
                temp = temp->right;
            }
        }
    }    
}
