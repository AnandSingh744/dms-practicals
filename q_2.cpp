/* Create a class RELATION, use Matrix notation to represent a relation. Include member
 functions to check if the relation is Reflexive, Symmetric, Anti-symmetric, Transitive.
 Using these functions check whether the given relation is: Equivalence or Partial Order
 relation or None*/
#include <iostream>
using namespace std;

class RELATION {
    int matrix[10][10], size;

public:
    void input() {
        cout << "Enter size of the set: ";
        cin >> size;
        cout << "Enter " << size << "x" << size << " relation matrix:\n";
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                cin >> matrix[i][j];
    }

    bool isReflexive() {
        for (int i = 0; i < size; i++)
            if (matrix[i][i] != 1) return false;
        return true;
    }

    bool isSymmetric() {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (matrix[i][j] != matrix[j][i]) return false;
        return true;
    }

    bool isAntiSymmetric() {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) return false;
        return true;
    }

    bool isTransitive() {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (matrix[i][j])
                    for (int k = 0; k < size; k++)
                        if (matrix[j][k] && !matrix[i][k]) return false;
        return true;
    }

    void checkRelationType() {
        bool R = isReflexive(), S = isSymmetric();
        bool AS = isAntiSymmetric(), T = isTransitive();

        cout << "\nReflexive: " << (R ? "Yes" : "No");
        cout << "\nSymmetric: " << (S ? "Yes" : "No");
        cout << "\nAnti-Symmetric: " << (AS ? "Yes" : "No");
        cout << "\nTransitive: " << (T ? "Yes" : "No") << "\n";

        if (R && S && T) cout << "\n=> Equivalence Relation\n";
        else if (R && AS && T) cout << "\n=> Partial Order Relation\n";
        else cout << "\n=> None\n";
    }
};

int main() {
    RELATION R;
    R.input();
    R.checkRelationType();
    return 0;
}
