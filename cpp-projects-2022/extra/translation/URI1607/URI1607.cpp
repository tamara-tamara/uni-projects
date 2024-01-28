//
// Created by User on 17.09.2023.
//
#include "iostream"
#include "string"

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string firstWord;
        cin >> firstWord;
        string secondWord;
        cin >> secondWord;
        int transformation = 0;
        for (int j = 0; j < firstWord.length(); ++j) {
            int counter = tolower(firstWord[j]) - 'a';
            int counter2 = tolower(secondWord[j]) - 'a';
            int gap = counter2 - counter;
            if (gap < 0) {
                gap += 26;
            }
            transformation += gap;
        }
        cout << transformation << endl;
    }
    return 0;
}