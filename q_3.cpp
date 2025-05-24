/* Write a Program that generates all the permutations of a given set of digits, with or
 without repetition*/
#include <iostream>
using namespace std;

// Function to swap two elements without using references
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Function to generate permutations without repetition
void permutationsWithoutRepetition(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= end; i++) {
        swap(arr, start, i);
        permutationsWithoutRepetition(arr, start + 1, end);
        swap(arr, start, i); // Backtrack
    }
}

// Function to generate permutations with repetition
void permutationsWithRepetition(int arr[], int current[], int n, int length) {
    if (length == 0) {
        for (int i = 0; i < n; i++) {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        current[n - length] = arr[i];
        permutationsWithRepetition(arr, current, n, length - 1);
    }
}

int main() {
    int digits[] = {1, 2, 3}; // Input digits
    int size = 3; // Manually specifying the size
    
    // Generate and display permutations without repetition
    cout << "Permutations without repetition:" << endl;
    permutationsWithoutRepetition(digits, 0, size - 1);
    
    // Generate and display permutations with repetition
    cout << "\nPermutations with repetition:" << endl;
    int current[size];
    permutationsWithRepetition(digits, current, size, size);
    
    return 0; // Indicate successful execution
}
