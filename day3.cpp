#include <iostream>
using namespace std;
int main() {
    cout <<"Enter first number: ";
    int a;
    cin >> a;
    cout <<"Enter second number: ";
    int b;
    cin >> b;
    cout <<"Sum = " << a + b << endl;
    cout <<"Difference = " << a - b << endl;
    cout <<"Product = " << a * b << endl;
    cout <<"Quotient = " << (float)a / b << endl;
    cout <<"Remainder = " << a % b << endl;
    return 0;
}