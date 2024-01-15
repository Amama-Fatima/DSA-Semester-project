#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>

#define V 9

class DijkstraAlgorithm {
public:
    // Constructor
    DijkstraAlgorithm();

    // Destructor
    ~DijkstraAlgorithm();

    // Function to find the vertex with the minimum distance value
    int minDistance(int dist[], bool sptSet[]);

    // Function to print the solution
    void printSolution(int dist[]);

    // Function to find the shortest path using Dijkstra's algorithm
    void dijkstra(int graph[V][V], int src);
};

#endif // DIJKSTRA_H
