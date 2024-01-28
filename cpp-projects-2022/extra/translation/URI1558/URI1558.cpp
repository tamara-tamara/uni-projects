//
// Created by User on 17.09.2023.
//
#include "iostream"
#include "cmath"

using namespace std;

int main() {
    int num;
    while (scanf("%d", &num) != EOF) {
        bool isRight = false;
        int maxOfNum = (int) round(sqrt(abs(num)));
        for (int i = 0; i <= maxOfNum; ++i) {
            for (int j = 0; j <= maxOfNum; ++j) {
                if (pow(i, 2) + pow(j, 2) == num) {
                    isRight = true;
                    break;
                }
            }
            if (isRight) {
                break;
            }
        }
        if (isRight) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}