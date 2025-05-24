/*complement: Assume Universal Set as per the input elements from the user.*/
#include <iostream>
using namespace std;

class SET {
public:
    int elements[100];
    int size;

    void inputSet() {
        cout << "Enter number of elements: ";
        cin >> size;
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> elements[i];
        }
    }

    void displaySet() {
        cout << "{ ";
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << "}\n";
    }

    SET complement(SET u) {
        SET result;
        result.size = 0;

        for (int i = 0; i < u.size; i++) {
            bool found = false;
            for (int j = 0; j < size; j++) {
                if (u.elements[i] == elements[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.elements[result.size++] = u.elements[i];
            }
        }
        return result;
    }
};

int main() {
    SET universal, userSet, compSet;

    cout << "Universal Set:\n";
    universal.inputSet();

    cout << "\nUser Set:\n";
    userSet.inputSet();

    compSet = userSet.complement(universal);

    cout << "\nUniversal Set: ";
    universal.displaySet();

    cout << "User Set: ";
    userSet.displaySet();

    cout << "Complement of User Set: ";
    compSet.displaySet();

    return 0;
}
