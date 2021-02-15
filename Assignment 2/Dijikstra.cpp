
  
#include <limits.h> 
#include <stdio.h> 
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector> 
using namespace std;
  
// Number of vertices in the graph 
#define V 10 
// A C / C++ program for Dijkstra's single source shortest
// path algorithm. The program is for adjacency matrix
// representation of the graph.
 

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// Function to print shortest path from source to j
// using parent array
void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;
 
    printPath(parent, parent[j]);
    cout << "-->";
    printf("%c", char(65 + j));
}
 
// A utility function to print the constructed distance
// array
int printSolution(int dist[], int n, int parent[])
{
    char src = 'A';
    printf("Vertex\t  Distance\tPath");
    for (int i = 1; i < V; i++)
    {
        printf("\n%c -> %c \t %d\t\t %c", src, char(65 + i), dist[i], src);
        printPath(parent, i);
    }
}
 
// Funtion that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V];  // The output array. dist[i] will hold
                  // the shortest distance from src to i
 
    // sptSet[i] will true if vertex i is included / in shortest
    // path tree or shortest distance from src to i is finalized
    bool sptSet[V];
 
    // Parent array to store shortest path tree
    int parent[V];
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to src
        // in first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet, there is
            // an edge from u to v, and total weight of path from
            // src to v through u is smaller than current value of
            // dist[v]
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }  
    }
 
    // print the constructed distance array
    printSolution(dist, V, parent);
}

int calc(int x[10], int y[10], int z[10], int source, int destination){
    float distance_x = pow(x[source] - x[destination], 2);
    float distance_y = pow(y[source] - y[destination], 2);
    float distance_z = pow(z[source] - z[destination], 2);
    float total_distance = distance_x + distance_y + distance_z;
    int real_distance = round(sqrt(total_distance));

    return real_distance;
}
  
// driver program to test above function 
int main() 
{ 
    int x[10];
    int y[10];
    int z[10];
    string coor_x;
    string coor_y; 
    string coor_z;
    string weight;
    string profit;
    string planet;
    int i = 0;

    ifstream planets("A2Planets.txt");

      while (getline(planets, planet, ' ') && getline(planets, coor_x, ' ') && getline(planets, coor_y, ' ') && getline(planets, coor_z, ' ') && getline(planets,weight, ' ') && getline(planets, profit) ) {
        // Output the text from the file
        x[i] = stoi(coor_x);
        y[i] = stoi(coor_y);
        z[i] = stoi(coor_z);

        i++;
    }

    int d_01 = calc(x, y, z, 0, 3);
    int d_02 = calc(x, y, z, 0, 5);
    int d_03 = calc(x, y, z, 0, 7);
    int d_04 = calc(x, y, z, 0, 9);

    int d_1 = calc(x, y, z, 1, 3);
    int d_2 = calc(x, y, z, 1, 4);
    int d_3 = calc(x, y, z, 1, 6);

    int d_4 = calc(x, y, z, 2, 4);
    int d_5 = calc(x, y, z, 2, 5);
    int d_6 = calc(x, y, z, 2, 8);

    int d_7 = calc(x, y, z, 3, 0);
    int d_8 = calc(x, y, z, 3, 1);
    int d_9 = calc(x, y, z, 3, 9);

    int d_10 = calc(x, y, z, 4, 1);
    int d_11 = calc(x, y, z, 4, 2);
    int d_12 = calc(x, y, z, 4, 6);
    int d_13 = calc(x, y, z, 4, 8);

    int d_14 = calc(x, y, z, 5, 0);
    int d_15 = calc(x, y, z, 5, 2);
    int d_16 = calc(x, y, z, 5, 7);

    int d_17 = calc(x, y, z, 6, 1);
    int d_18 = calc(x, y, z, 6, 4);
    int d_19 = calc(x, y, z, 6, 8);
    int d_20 = calc(x, y, z, 6, 9);

    int d_21 = calc(x, y, z, 7, 0);
    int d_22 = calc(x, y, z, 7, 5);
    int d_23 = calc(x, y, z, 7, 8);
    int d_24 = calc(x, y, z, 7, 9);

    int d_25 = calc(x, y, z, 8, 2);
    int d_26 = calc(x, y, z, 8, 4);
    int d_27 = calc(x, y, z, 8, 6);
    int d_28 = calc(x, y, z, 8, 7);

    int d_31 = calc(x, y, z, 9, 0);
    int d_32 = calc(x, y, z, 9, 3);
    int d_33 = calc(x, y, z, 9, 6);
    int d_34 = calc(x, y, z, 9, 7);


    int graph[V][V] = { { 0   , 0   , 0   , d_7 , 0   , d_14, 0   , d_21, 0   , d_31}, 
                        { 0   , 0   , 0   , d_8 , d_10, 0   , d_17, 0   , 0   , 0   }, 
                        { 0   , 0   , 0   , 0   , d_11, d_15, 0   , 0   , d_25, 0   }, 
                        { d_01, d_1 , 0   , 0   , 0   , 0   , 0   , 0   , 0   , d_32}, 
                        { 0   , d_2 , d_4 , 0   , 0   , 0   , d_18, 0   , d_26, 0   }, 
                        { d_02, 0   , d_5 , 0   , 0   , 0   , 0   , d_22, 0   , 0   }, 
                        { 0   , d_3 , 0   , 0   , d_12, 0   , 0   , 0   , d_27, d_33}, 
                        { d_03, 0   , 0   , 0   , 0   , d_16, 0   , 0   , d_28, d_34}, 
                        { 0   , 0   , d_6 , 0   , d_13, 0   , d_19, d_23, 0   , 0   }, 
                        { d_04, 0   , 0   , d_9 , 0   , 0   , d_20, d_24, 0   , 0   } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
} 
