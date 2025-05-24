//union and Intersection of two Sets.
#include <iostream>
using namespace std;

// Function to find the union of two sets
void findUnion(int set1[], int size1, int set2[], int size2) {
    cout << "Union: { ";
    
    // Print all elements of set1
    for (int i = 0; i < size1; i++) {
        cout << set1[i] << " ";
    }

    // Print elements of set2 that are not in set1
    for (int i = 0; i < size2; i++) {
        bool isPresent = false;
        for (int j = 0; j < size1; j++) {
            if (set2[i] == set1[j]) {
                isPresent = true;
                break;
            }
        }
        if (!isPresent) {
            cout << set2[i] << " ";
        }
    }
    cout << "}" << endl;
}

// Function to find the intersection of two sets
void findIntersection(int set1[], int size1, int set2[], int size2) {
    cout << "Intersection: { ";
    for (int i = 0; i < size2; i++) {
        for (int j = 0; j < size1; j++) {
            if (set2[i] == set1[j]) {
                cout << set2[i] << " ";
                break;  // Avoid duplicate prints
            }
        }
    }
    cout << "}" << endl;
}

int main() {
    int size1, size2;
    
    // Input for the first set
    cout << "Enter the size of the first set: ";
    cin >> size1;
    int set1[size1];
    cout << "Enter " << size1 << " elements: ";
    for (int i = 0; i < size1; i++) {
        cin >> set1[i];
    }

    // Input for the second set
    cout << "Enter the size of the second set: ";
    cin >> size2;
    int set2[size2];
    cout << "Enter " << size2 << " elements: ";
    for (int i = 0; i < size2; i++) {
        cin >> set2[i];
    }

    // Finding Union
    findUnion(set1, size1, set2, size2);

    // Finding Intersection
    findIntersection(set1, size1, set2, size2);

    return 0;
}
