//
// Created by User on 10.11.2023.
//

#include "iostream"
#include <string>
#include <unordered_map>
#include <unordered_set>

//using namespace igloo;
using namespace std;


std::string duplicate_encoder(const std::string &word) {
    unordered_map<int, char> counter_of_freq;
    std::unordered_set<char> frequency;
    std::string result;

    for (char i: word) {
        i = tolower(i);
        frequency.insert(i);
        counter_of_freq[i]++;

    }
    for (char i: word) {
        i = tolower(i);
        if (counter_of_freq[i] == 1) {
            result += "(";
        } else {
            result += ")";
        }
    }

    return result;
}

int main() {
    std::string a = duplicate_encoder("Success");
    cout << a;

    return 0;
}