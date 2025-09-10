#include<iostream>
using namespace std;

int main() {
    for (int i=1; i<=10; i++) {
        cout << i << " ";
    }

    int j = 1;
    while (j <= 10) {
        cout << j << " ";
        j++;
    }

    int k = 1;
    do {
        cout << k << " ";
        k++;
    } while (k <= 10);
}