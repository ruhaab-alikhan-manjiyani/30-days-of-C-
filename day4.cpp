#include <iostream>
using namespace std;
int main() {
    cout << "Enter two numbers: ";
    int a, b;
    cin >> a >> b;
    if (b != 0) {
        cout << "Quotient =  " << (float)a / b << endl;
        cout << "Remainder = " << a % b << endl;
    } else {
        cout << "Error: Division by zero!" << endl;
    }
    return 0;
}