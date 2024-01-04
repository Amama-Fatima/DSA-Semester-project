#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "Book.h"
#include "Graph.h"
using namespace std;

extern Graph bookGraph;

int determineEdgeWeight(Book* b1, Book* b2);

void Graph::addVertex(int id){
    if (id >= 0 && id <= numVertices) {
        Vertex v(id);
        vertices[id-1] = v;
    } else {
        cout << "Invalid vertex id: " << id << endl;
    }
}


void Graph::addEdge(int src, int dest, int weight) {
    for (const Edge& e : vertices[src-1].edges) {
        
        if (e.dest == dest) {
            
            return;
        }
    }
    Edge forwardEdge;
    forwardEdge.dest = dest;
    forwardEdge.weight = weight;

    Edge reverseEdge;
    reverseEdge.dest = src;
    reverseEdge.weight = weight;
    vertices[src-1].edges.push_back(forwardEdge);


    vertices[dest-1].edges.push_back(reverseEdge);
    numEdges++;
}





void CreateGraph(Book* head) {
    Book* temp = head;
    while (temp != NULL) {
        // Add vertex
        bookGraph.addVertex(temp->id);
        temp = temp->right;
    }
    

    // Add edges based on genre similarity
    temp = head;
    int srcId, destId;
    while (temp != NULL) {
        Book* next = head;

        srcId = temp->id;
        
        while (temp != NULL && next != NULL) {
            destId = next->id;
            if (srcId != destId) {
                int weight = determineEdgeWeight(temp, next);
                if (weight > 6) {
                    bookGraph.addEdge(srcId, destId, weight);
                }
            }
            next = next->right;
        }

        temp = temp->right;
    }

    cout << "Printing all vertices's id: " << endl;
    for(Vertex v : bookGraph.vertices){
        cout << v.id << endl;
    }

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



void Graph::generateDotFile(string filename){
    cout << "Generating dot file..." << endl;
    ofstream dotFile(filename);
    dotFile << "graph G {" << endl;

    for(Vertex v : vertices){
        dotFile << v.id << ";" << endl;
        for(Edge e : v.edges){
                dotFile << v.id << "  --  " << e.dest << " weight: " << e.weight << " ;" << endl;
        }
    }

    dotFile << "}" << endl;
    dotFile.close();
    cout << "Dot file generated." << endl;
}




void Graph::printGraph() {
    for (const Vertex& v : vertices) {
        cout << "Vertex " << v.id << ": ";
        for (const Edge& e : v.edges) {
            cout << "(" << e.dest << ", " << e.weight << ") ";
        }
        cout << endl;
    }
}








// for(Edge e : bookGraph.vertices[destId].edges){
//                         cout << e.dest << endl;
//                     }
//                     bookGraph.addEdge(srcId, destId, weight);



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