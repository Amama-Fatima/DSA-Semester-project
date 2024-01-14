#include <iostream>
#include <vector>

using namespace std;

class GraphAdj{
public:
    int numVertices;
    int** adjacencyMatrix;
    int numEdges;

    GraphAdj(int numVertices) : numVertices(numVertices), numEdges(0) {
        // Initialize the adjacency matrix with all zeros
        adjacencyMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            adjacencyMatrix[i] = new int[numVertices]();
        }
    }

    void addEdge(int src, int dest, int weight);
    void printAdjacencyMatrix();
    void printBFS(int start);
    void printDFS(int start);
    void printDijkstra(int start);
    void printPrim(int start);
    void generateDotFile(string filename);
    int getNumVertices();
    int** getAdjacencyMatrix();
    
};





    // vector<vector<int>> adjacencyMatrix;
    // int numVertices;
    // int numEdges;

    // GraphAdj(int numVertices) : numVertices(numVertices), numEdges(0) {
    //     // Initialize the adjacency matrix with all zeros
    //     adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));
    // }
    // a 2d array of ints