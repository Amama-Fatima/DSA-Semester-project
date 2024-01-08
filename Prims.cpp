#include <bits/stdc++.h>
#include "heap.cpp"
using namespace std;


int* printHeap(CustomHeap* heap, int numVertices);

void calculateDistances(int parent[], int numVertices, int distances[]) {
    for (int i = 0; i < numVertices; i++) {
        int currentVertex = i;
        distances[currentVertex] = 0;

        while (parent[currentVertex] != -1) {
            distances[currentVertex]++;
            currentVertex = parent[currentVertex];
        }
    }
}

int minWeight(int weight[], bool mstSet[], int numVertices){
    int min = INT_MAX, min_index;

    for(int v=0; v < numVertices; v++){
        if(mstSet[v]==false && weight[v] < min){
            min = weight[v];
            min_index = v;
        }
    }
    return min_index;
}


void printMST(int parent[], int** graph, int root, int numVertices) {
    cout << "Edge \tWeight\n";
    for (int i = 0; i < numVertices; i++) {
        if (i != root) {
            cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
            
        }
    }
}



int* primMST(int** graph, int srcId, int numVertices){

    //array to store constructed MST
    int parent[numVertices];

    //weight values used to pick minimum weight edge in cut
    int weight[numVertices];

    //to represent set of vertices not yet included in MST
    bool mstSet[numVertices];

    int distances[numVertices];

    //initialize all weights as infinite
    for(int i = 0; i < numVertices; i++){
        weight[i] = INT_MAX;
        mstSet[i] = false;
    }


    weight[srcId-1] = 0;

    parent[srcId-1] = -1; //root


    for(int count = 0; count < numVertices-1; count++){
        int u = minWeight(weight, mstSet, numVertices);

        mstSet[u] = true;

        for(int v = 0; v < numVertices; v++){
            if(graph[u][v] && mstSet[v] == false && (-graph[u][v]) < weight[v]){
                parent[v] = u;
                // cout << " Change of parent parent[" << v << "] = " << u << endl;
                weight[v] = -graph[u][v];
            }
        }
    }

    //print the weight array
    // for(int i = 0; i < numVertices; i++){
    //     cout << "weight[" << i << "] = " << weight[i] << endl;
    // }


    printMST(parent, graph, srcId-1, numVertices);

    calculateDistances(parent, numVertices, distances);


    CustomHeap heap = CustomHeap();

    for (int i = 0; i < numVertices; i++) {
        // Create the pair: {distance, {vertex, weight}}
        pair<int, pair<int, int>> currentPair = {distances[i], {i + 1, -weight[i]}};
        heap.add(currentPair);
    }

    int* books = printHeap(&heap, numVertices);
    return books;

}

int* printHeap(CustomHeap* heap, int numVertices){
    //removing from heap and printing
    int books[numVertices];
    int i=0;
    cout << "Following are the ids of the book we would recommend: \n";
    while (!(*heap).isEmpty()) {
        pair<int, pair<int, int>> currentPair = (*heap).poll();
        // cout << "Vertex: " << currentPair.second.first << " Distance: " << currentPair.first << " Weight: " << currentPair.second.second << endl;
        cout << currentPair.second.first << endl;
        books[i] = currentPair.second.first;
        i++;
    }
    return books;
}