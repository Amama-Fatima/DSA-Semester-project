#include <iostream>
#include <fstream>
#include <vector>
#include "GraphAdj.h"
#include "Book.h"
using namespace std;


extern GraphAdj bookAdjGraph;

void GraphAdj::addEdge(int src, int dest, int weight){
    adjacencyMatrix[src-1][dest-1] = weight;
    adjacencyMatrix[dest-1][src-1] = weight;
    numEdges++;
}



int determineEdgeWeight(Book* b1, Book* b2){
    int commonGenres = 0;
    for(Genre genre1 : b1->genres){
        for(Genre genre2 : b2->genres){
            if(genre1.name == genre2.name){
                commonGenres++;
                
            }
        }
    }
    return commonGenres;
}



void createAdjacentGraph(Book* head){
    Book* temp = head;

    // Add edges based on genre similarity
    temp = head;
    int srcId, destId;
    while(temp != NULL){
        srcId = temp->id;
        Book* temp2 = temp->right;
        while(temp2 != NULL){
            destId = temp2->id;
            int weight = determineEdgeWeight(temp, temp2);
            if(weight > 3){
                bookAdjGraph.addEdge(srcId, destId, weight);
            }
            temp2 = temp2->right;
        }
        temp = temp->right;
    }
}

void GraphAdj::printAdjacencyMatrix(){
    cout << "Printing adjacency matrix: " << endl;
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}


void GraphAdj::generateDotFile(string filename) {
    cout << "Generating dot file..." << endl;
    ofstream dotFile(filename);
    dotFile << "graph G {" << endl;

    for (int i = 0; i < numVertices; ++i) {
        dotFile << (i + 1) << ";" << endl;
        for (int j = 0; j < numVertices; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                dotFile << (i + 1) << "  --  " << (j + 1) << " weight: " << adjacencyMatrix[i][j] << " ;" << endl;
            }
        }
    }

    dotFile << "}" << endl;
    dotFile.close();
    cout << "Dot file generated." << endl;
}

int GraphAdj::getNumVertices() {
        return numVertices;
    }

int** GraphAdj::getAdjacencyMatrix() {
        return adjacencyMatrix;
    }