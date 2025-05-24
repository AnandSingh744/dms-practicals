/* set Difference and Symmetric Difference between two sets.*/
#include <iostream>
using namespace std;

class SET {
    int arr[100];
    int size;

public:
    void input() {
        cout << "Enter number of elements: ";
        cin >> size;
        cout << "Enter elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "{ ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "}\n";
    }

    // Set Difference: A - B
    void difference(SET B) {
        cout << "A - B (Difference): { ";
        for (int i = 0; i < size; i++) {
            bool found = false;
            for (int j = 0; j < B.size; j++) {
                if (arr[i] == B.arr[j]) {
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << arr[i] << " ";
        }
        cout << "}\n";
    }

    // Symmetric Difference: (A - B) ∪ (B - A)
    void symmetricDifference(SET B) {
        cout << "A Δ B (Symmetric Difference): { ";

        // A - B
        for (int i = 0; i < size; i++) {
            bool found = false;
            for (int j = 0; j < B.size; j++) {
                if (arr[i] == B.arr[j]) {
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << arr[i] << " ";
        }

        // B - A
        for (int i = 0; i < B.size; i++) {
            bool found = false;
            for (int j = 0; j < size; j++) {
                if (B.arr[i] == arr[j]) {
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << B.arr[i] << " ";
        }

        cout << "}\n";
    }
};

// Example usage
int main() {
    SET A, B;

    cout << "Input for Set A:\n";
    A.input();

    cout << "Input for Set B:\n";
    B.input();

    cout << "Set A: ";
    A.display();

    cout << "Set B: ";
    B.display();

    A.difference(B);
    A.symmetricDifference(B);

    return 0;
}
