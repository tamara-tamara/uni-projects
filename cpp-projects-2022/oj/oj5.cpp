//
// Created by User on 24.09.2023.
//
#include <string>
#include "iostream"

using namespace std;


bool tidyNumber(int number) {
    bool isTidy = true;
    string n = to_string(number);
    int size = n.size();
    for (int i = 1; i < size; ++i) {
        if (n[i - 1] <= n[i])
            continue;
        isTidy = false;
        break;

    }
    return isTidy;
}

int main() {
    cout << tidyNumber(1024) << endl;
    return 0;
}