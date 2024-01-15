#include <iostream>
#include <vector>
#include <queue>
#include "GraphAdj.h"
#include "Book.h"
#include "BFS.h"

void BFS::performBFS(GraphAdj& graph, int startVertex) {
    int numVertices = graph.getNumVertices();
    std::vector<bool> visited(numVertices, false);
    std::queue<int> bfsQueue;

    visited[startVertex - 1] = true;
    bfsQueue.push(startVertex);

    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        std::cout << "Book ID: " << currentVertex << " ";
        // If you have Book objects, you can access them using books[currentVertex - 1]

        bfsQueue.pop();

        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (graph.getAdjacencyMatrix()[currentVertex - 1][neighbor] != 0 && !visited[neighbor]) {
                visited[neighbor] = true;
                bfsQueue.push(neighbor + 1);
            }
        }
    }
}
