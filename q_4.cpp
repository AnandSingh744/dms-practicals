/*For any number n, write a program to list all the solutions of the equation x1 + x2 + x3 +
 ...+ xn = C, where C is a constant (C<=10) and x1, x2,x3,...,xn are nonnegative integers,
 using brute force strategy.*/
#include <iostream>
using namespace std;

const int MAX = 10; 

int n, C;
int values[20];  
int count = 0;   


void findCombinations(int index, int sumSoFar) {
    if (index == n) {
        if (sumSoFar == C) {
            
            cout << "(";
            for (int i = 0; i < n; ++i) {
                cout << values[i];
                if (i < n - 1) cout << ", ";
            }
            cout << ")\n";
            count++;  
        }
        return;
    }

    
    for (int i = 0; i <= C - sumSoFar; ++i) {
        values[index] = i;
        findCombinations(index + 1, sumSoFar + i);
    }
}

int main() {
    cout << "Enter number of variables (n): ";
    cin >> n;
    cout << "Enter value of constant (C <= 10): ";
    cin >> C;

    if (C > MAX || n <= 0) {
        cout << "Invalid input. Make sure C <= 10 and n > 0.\n";
        return 1;
    }

    cout << "\nAll combinations of x1 + x2 + ... + x" << n << " = " << C << ":\n\n";
    findCombinations(0, 0);

    cout << "\nTotal number of combinations: " << count << "\n";

    return 0;
}

/*index=0,sumsofar=0
 1}
  x1=0
  |
  x2=0->sum=0
  |
  x2=1->sum=1
   |
   x2=2->sum=2
   |
   x3=3->sum=3  (0,3) prints
2}
  x1=1
  |
  x2=0->sum=1
  |
  x2=1->sum=2
   |
   x2=2->sum=3  (1,2) prints

 3}
 x1=2
  |
  x2=0->sum=2
  |
  x2=1->sum=3
 
 4}
 x1=3 
  |
  x2=0->sum=3 (3,0) prints


  total combinations=4
  (0,3)
  (1,2)
  (2,1)
  (3,0)

*/

