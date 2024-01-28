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
        string a;
        cin >> a;
        string b;
        cin >> b;

        if ((a.length() < b.length())) {
            cout << "nao encaixa" << endl;
        } else if (a.substr(a.length() - b.length()) == b) {
            cout << "encaixa" << endl;
        } else {
            cout << "nao encaixa" << endl;
        }

    }
    return 0;
}