/*Write a Program to check if a given graph is a complete graph. Represent the graph using
 the Adjacency Matrix representation.*/
#include <iostream>
using namespace std;

// Function to check if a graph is complete
int isCompleteGraph(int matrix[][10], int n) {
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (matrix[i][j] == 0) { 
                    return 0; // If any pair is not connected, it's not complete
                }
            }
        }
    }
    return 1; // If all pairs are connected, it's complete
}

int main() {
    int n; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;
    
    int matrix[10][10]; // Maximum allowed size
    
    cout << "Enter the adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Check if the graph is complete
    if (isCompleteGraph(matrix, n)) {
        cout << "Complete Graph" << endl;
    } else {
        cout << "Not a Complete Graph" << endl;
    }

    return 0;
}
