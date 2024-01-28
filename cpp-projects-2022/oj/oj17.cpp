//
// Created by User on 12.10.2023.
//
#include <list>
#include "iostream"
#include "string"

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin.ignore();
    while (n != 0) {
        getline(cin, s);
        list<char> result;
        list<char>::iterator iterator = result.begin();
        for (char i: s) {
            switch (i) {
                case '<':
                    if (iterator != result.begin()) {
                        iterator = result.erase(--iterator);
                    }
                    break;
                case '[':
                    iterator = result.begin();
                    break;
                case ']':
                    iterator = result.end();
                    break;
                default:
                    iterator = result.insert(iterator, i);
                    iterator++;
            }
        }
        for (char i: result) {
            cout << i;
        }
        cout << endl;
        n--;
    }
    return 0;
}