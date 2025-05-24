/*Write a Program to accept a directed graph G and compute the in-degree and out-degree
 of each vertex.*/
#include <iostream>
using namespace std;

int main() {
    int n; // number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[100][100]; // adjacency matrix
    cout << "Enter the adjacency matrix (0 or 1 for each edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Arrays to store in-degree and out-degree
    int in_degree[100] = {0};
    int out_degree[100] = {0};

    // Calculate in-degree and out-degree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                out_degree[i]++; // outgoing edge from i
                in_degree[j]++;  // incoming edge to j
            }
        }
    }

    // Print the results
    cout << "\nVertex | In-Degree | Out-Degree\n";
        for (int i = 0; i < n; i++) {
           cout << "   " << i << "    |     " << in_degree[i] << "     |     " << out_degree[i] << "\n";
}


    return 0;
}
