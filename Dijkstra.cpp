#include "Dijkstra.h"
#include <limits>


DijkstraAlgorithm::DijkstraAlgorithm() {
    // Constructor implementation (if needed)
}

DijkstraAlgorithm::~DijkstraAlgorithm() {
    // Destructor implementation (if needed)
}

int DijkstraAlgorithm::minDistance(int dist[], bool sptSet[]) {
    int min = std::numeric_limits<int>::max(), min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void DijkstraAlgorithm::printSolution(int dist[]) {
    std::cout << "Vertex \t Distance from Source" << std::endl;
    for (int i = 0; i < V; i++)
        std::cout << i << " \t\t\t\t" << dist[i] << std::endl;
}

void DijkstraAlgorithm::dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = std::numeric_limits<int>::max(), sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != std::numeric_limits<int>::max() &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}
