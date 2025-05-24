// subset: Check whether one set is a subset of the other or not.
#include <iostream>
using namespace std;

bool isSubset(int set1[], int size1, int set2[], int size2) {
    for (int i = 0; i < size2; i++) {
        int j;
        for (j = 0; j < size1; j++) {
            if (set2[i] == set1[j]) {
                break;
            }
        }
        if (j == size1) return false;
    }
    return true;
}

int main() {
    int size;
    cout << "Enter the size of the set: ";
    cin >> size;

    int mySet[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> mySet[i];
    }

    int size2;
    cout << "Enter the size of the subset to check: ";
    cin >> size2;

    int subset[size2];
    cout << "Enter " << size2 << " elements: ";
    for (int i = 0; i < size2; i++) {
        cin >> subset[i];
    }

    if (isSubset(mySet, size, subset, size2)) {
        cout << "The second set is a subset of the first set." << endl;
    } else {
        cout << "The second set is not a subset of the first set." << endl;
    }

    return 0;
}
