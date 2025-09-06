#include <iostream>
using namespace std;
int main() {
    string name;
    int number;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your favorite number: ";
    cin >> number;
    cout << "Hello, " << name << "! Your favorite number is " << number << "." << endl;
    return 0;
}