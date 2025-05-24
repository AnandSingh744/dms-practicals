/*cartesian Product of Sets.*/
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

    void cartesianProduct(SET B) {
        cout << "A × B (Cartesian Product): { ";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < B.size; j++) {
                cout << "(" << arr[i] << "," << B.arr[j] << ") ";
            }
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

    A.cartesianProduct(B);

    return 0;
}
