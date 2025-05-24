/*Write a Program to evaluate a polynomial function. (For example store f(x) = 4n2 + 2n +
 9 in an array and for a given value of n, say n = 5, compute the value of f(n))*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    int coeff[100]; 
    cout << "Enter the coefficients (from highest degree to constant term):\n";
    for (int i = 0; i <= degree; i++) {
        cout << "Coefficient of n^" << (degree - i) << ": ";
        cin >> coeff[i];
    }

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = 0;

    for (int i = 0; i <= degree; i++) {
        int power = degree - i;
        result += coeff[i] * pow(n, power);
    }

    cout << "Value of the polynomial at n = " << n << " is " << result << endl;

    return 0;
}
