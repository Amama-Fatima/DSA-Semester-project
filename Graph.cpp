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
};

class Graph{
    private:
        vector<Vertex> vertices;
        int numVertices;
        int numEdges;
        //graph will be directed in this program
    public:
        Graph(int numVertices, bool directed);
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
};

void Graph::addVertex(int id){
    Vertex v(id);
    vertices.push_back(v);
    numVertices++;
}

void Graph::addEdge(int src, int dest, int weight){
    Edge e;
    e.dest = dest;
    e.weight = weight;
    vertices[src].edges.push_back(e);
    e.dest = src;
    vertices[dest].edges.push_back(e);
    numEdges++;
}
















// void printKruskal();
//         void printBellmanFord(int start);
//         void printFloydWarshall();
//         void printTopologicalSort();
//         void printMST();
//         void printEulerianPath();
//         void printHamiltonianPath();
//         void printShortestPath();
//         void printLongestPath();
//         void printMaxFlow();
//         void printMinCut();
//         void printBipartite();
//         void printArticulationPoints();
//         void printBridges();
//         void printStronglyConnectedComponents();
//         void printTravelingSalesman();
//         void printChinesePostman();
//         void printVertexCover();
//         void printDominatingSet();
//         void printIndependentSet();
//         void printClique();
//         void printChromaticNumber();
//         void printPlanarity();
//         void printEulerianCircuit();
//         void printHamiltonianCycle();
//         void printIsomorphism();
//         void printGraphIsomorphism();
//         void printSubgraphIsomorphism();
//         void printGraphAutomorphism();
//         void printSubgraphAutomorphism();
//         void printGraphMinor();
//         void printSubgraphMinor();
//         void printGraphHomeomorphism();
//         void printSubgraphHomeomorphism();
//         void printGraphEmbedding();
//         void printSubgraphEmbedding();
//         void printGraphIsomorphismCount();
//         void printSubgraphIsomorphismCount();
//         void printGraphAutomorphismCount();
//         void printSubgraphAutomorphismCount();
//         void printGraphMinorCount();
//         void printSubgraphMinorCount();
//         void printGraphHomeomorphismCount();
//         void printSubgraphHomeomorphismCount();
//         void printGraphEmbeddingCount();
//         void printSubgraphEmbeddingCount();
//         void printGraphIsomorphismDecision();
//         void printSubgraphIsomorphismDecision();
//         void printGraphAutomorphismDecision();
//         void printSubgraphAutomorphismDecision();
//         void printGraphMinorDecision();