﻿#include <iostream> 
using namespace std;

int main() {

    int n;
    cout << "Enter Number: ";
    cin >> n;

    int numRows = n;
    if (n == 9) {
        numRows = n % 5 + 5;
    }

    for (int i = 0; i < numRows; i++) {
        // Виводимо пробіли перед лінійкою 
        for (int j = 1; j <= numRows - i; j++) {
            cout << " ";
        }


        for (int j = 0; j <= i; j++) {
            cout << j;
        }

        // Виводимо цифру для лінійки 
        for (int j = 0; j <= i - 1; j++) {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}