//
// Created by User on 11.11.2023.
//
#include <vector>
#include <map>
#include "string"
#include "iostream"

using namespace std;

int main() {
    string words;
    map<string, string> dict;
    vector<string> input;
    while (getline(cin, words) && !words.empty()) {
        string first;
        string second;
        for (int i = 0; i < words.length(); ++i) {
            if (words[i] == ' ') {
                first = words.substr(0, words.length() - (words.length() - i));
                second = words.substr(words.length() - (words.length() - i) + 1, words.length() - first.length());
                break;
            }
        }
        dict[second] = first;
    }
    string tests;
    while (cin >> tests) {
        map<string, string>::iterator iterator;
        iterator = dict.find(tests);
        if (iterator != dict.end()) {
            cout << iterator->second << endl;

        } else
            cout << "eh" << endl;
    }
    return 0;
}