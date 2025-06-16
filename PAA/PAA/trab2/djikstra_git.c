#include <stdio.h>
#include <stdbool.h>
#define INF 99999

// A function to find the vertex with the minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[],int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int V) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Dijkstra's algorithm for adjacency matrix representation of the graph
void dijkstra(int V, int src, int Graph[V][V]) {
    int dist[V];  // The output array. dist[i] will hold the shortest distance from src to i
    bool sptSet[V];  // sptSet[i] will be true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INF, sptSet[i] = false;

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

// Driver code
int main() {
    int graph[V][V] = {{0, 9, 6, 5, 3},
                       {9, 0, 0, 0, 0},
                       {6, 0, 0, 0, 0},
                       {5, 0, 0, 0, 0},
                       {3, 0, 0, 0, 0}};

    dijkstra(graph, 0);
    return 0;
}
