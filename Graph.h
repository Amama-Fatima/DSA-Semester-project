#include <iostream>
#include <list>
#include <vector>

using namespace std;
struct Edge{
    int dest;
    int weight;
};

struct Vertex{
    int id;
    list<Edge> edges;
    //constructor
    Vertex(int id) : id(id){}
    Vertex() : id(-1) {} 
};

class Graph{
        //graph will be directed in this program
    public:
        vector<Vertex> vertices;
        int numVertices;
        int numEdges;
        Graph(int numVertices) : numVertices(numVertices), numEdges(0) {
        vertices.resize(numVertices, Vertex(-1)); // Initialize with default values
        }

        void addVertex(int id);
        void addEdge(int src, int dest, int weight);
        void removeEdge(int src, int dest);
        void printGraph();
        void printEdges(int vertex);
        void printBFS(int start);
        void printDFS(int start);
        void printDijkstra(int start);
        void printPrim(int start);
        void printSub();
        void generateDotFile(string filename);
};