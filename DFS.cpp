#include <iostream>
#include <vector>
#include <stack>
#include "GraphAdj.h"
#include "Book.h"

void DFS(GraphAdj& graph, int startVertex, Book* books[]) {
    int numVertices = graph.getNumVertices();
    std::vector<bool> visited(numVertices, false);
    std::stack<int> stack;

    visited[startVertex - 1] = true;
    stack.push(startVertex);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        std::cout << "Book ID: " << currentVertex << " ";
        // If you have Book objects, you can access them using books[currentVertex - 1]

        stack.pop();

        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (graph.getAdjacencyMatrix()[currentVertex - 1][neighbor] != 0 && !visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor + 1);
            }
        }
    }
}
