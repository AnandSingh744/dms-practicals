#include <iostream>
#include <cmath>
using namespace std;

class SET {
    int arr[50], size;

public:
    void input() {
        cout << "Enter number of elements in the set: ";
        cin >> size;
        cout << "Enter elements:\n";
        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }

    void display() {
        cout << "{ ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "}\n";
    }

    bool isMember(int element) {
        for (int i = 0; i < size; i++)
            if (arr[i] == element) return true;
        return false;
    }

    void powerSet() {
        int powSize = pow(2, size);
        cout << "Power set:\n";
        for (int i = 0; i < powSize; i++) {
            cout << "{ ";
            for (int j = 0; j < size; j++)
                if (i & (1 << j))
                    cout << arr[j] << " ";
            cout << "}\n";
        }
    }

    bool isSubset(SET B) {
        for (int i = 0; i < B.size; i++) {
            bool found = false;
            for (int j = 0; j < size; j++) {
                if (B.arr[i] == arr[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }

    void unionSet(SET B) {
        cout << "Union: { ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        for (int i = 0; i < B.size; i++) {
            bool found = false;
            for (int j = 0; j < size; j++) {
                if (B.arr[i] == arr[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) cout << B.arr[i] << " ";
        }
        cout << "}\n";
    }

    void intersection(SET B) {
        cout << "Intersection: { ";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < B.size; j++) {
                if (arr[i] == B.arr[j])
                    cout << arr[i] << " ";
            }
        }
        cout << "}\n";
    }

    void difference(SET B) {
        cout << "A - B: { ";
        for (int i = 0; i < size; i++) {
            bool found = false;
            for (int j = 0; j < B.size; j++) {
                if (arr[i] == B.arr[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) cout << arr[i] << " ";
        }
        cout << "}\n";
    }

    void symmetricDifference(SET B) {
        cout << "Symmetric Difference: { ";

        // A - B
        for (int i = 0; i < size; i++) {
            bool found = false;
            for (int j = 0; j < B.size; j++) {
                if (arr[i] == B.arr[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) cout << arr[i] << " ";
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
            if (!found) cout << B.arr[i] << " ";
        }

        cout << "}\n";
    }

    void cartesianProduct(SET B) {
        cout << "Cartesian Product: { ";
        for (int i = 0; i < size; i++)
            for (int j = 0; j < B.size; j++)
                cout << "(" << arr[i] << "," << B.arr[j] << ") ";
        cout << "}\n";
    }

    void complement(SET universal) {
        cout << "Complement: { ";
        for (int i = 0; i < universal.size; i++) {
            bool found = false;
            for (int j = 0; j < size; j++) {
                if (universal.arr[i] == arr[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) cout << universal.arr[i] << " ";
        }
        cout << "}\n";
    }
};

// --------------------- MAIN MENU ---------------------
int main() {
    SET A, B, U;
    int choice, element;

    cout << "Enter Universal Set:\n";
    U.input();
    cout << "Enter Set A:\n";
    A.input();
    cout << "Enter Set B:\n";
    B.input();

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Check Membership\n";
        cout << "2. Power Set of A\n";
        cout << "3. Check if B is subset of A\n";
        cout << "4. Union of A and B\n";
        cout << "5. Intersection of A and B\n";
        cout << "6. Complement of A\n";
        cout << "7. A - B (Difference)\n";
        cout << "8. Symmetric Difference\n";
        cout << "9. Cartesian Product A x B\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to check in A: ";
                cin >> element;
                cout << (A.isMember(element) ? "Yes\n" : "No\n");
                break;
            case 2:
                A.powerSet();
                break;
            case 3:
                cout << (A.isSubset(B) ? "B is subset of A\n" : "B is NOT subset of A\n");
                break;
            case 4:
                A.unionSet(B);
                break;
            case 5:
                A.intersection(B);
                break;
            case 6:
                A.complement(U);
                break;
            case 7:
                A.difference(B);
                break;
            case 8:
                A.symmetricDifference(B);
                break;
            case 9:
                A.cartesianProduct(B);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
