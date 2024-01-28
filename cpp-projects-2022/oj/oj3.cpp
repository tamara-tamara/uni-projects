//
// Created by User on 23.09.2023.
//

#include "iostream"

using namespace std;

unsigned int realNumbers(unsigned int n) {
    return n - (n / 2 + n / 3 + n / 5 - n / 6 - n / 10 - n / 15 + n / 30);
}

int main() {
    cout << realNumbers(5) << endl;
    return 0;
}