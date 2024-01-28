//
// Created by User on 17.09.2023.
//
#include "iostream"
#include "string"

using namespace std;

int main() {
    while (true) {
        int numOfDistricts;
        cin >> numOfDistricts;
        if (numOfDistricts == 0) {
            break;
        }
        bool isCorrectN = false;
        int correctOrder = 1;
        while (true) {
            int firstDistrict = 0;
            for (int i = 2; i <= numOfDistricts - 1; i++) {
                int nextDistrict = firstDistrict + correctOrder;
                firstDistrict = nextDistrict % i;
            }
            if (firstDistrict == 11) {
                isCorrectN = true;
            }
            if (isCorrectN) {
                break;
            }
            correctOrder++;
        }
        cout << correctOrder << endl;
    }

    return 0;
}
