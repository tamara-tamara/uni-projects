//
// Created by User on 06.10.2023.
//
#include<string>
#include <vector>
#include "iostream"

bool scramble(const std::string &s1, const std::string &s2) {
    bool is_scramble = false;
    if (s1.size() < s2.size()) {
        return is_scramble;
    }
    if (s1 == s2) {
        is_scramble = true;
        return is_scramble;
    }

    std::vector<int> letters(26, 0);

    for (int i = 0; i < (int) s1.size(); ++i) {
        letters[s1[i] - 'a']++;
    }

    for (int i = 0; i < (int) s2.size(); ++i) {
        letters[s2[i] - 'a']--;
    }
    for (int i = 0; i < (int) letters.size(); i++) {
        if (letters[i] < 0) {
            is_scramble = false;
            return is_scramble;
        }
    }
    is_scramble = true;
    return is_scramble;
}

int main() {
    bool res = scramble("aabbcamaomsccdd", "commas");

    std::cout << res << std::endl;
    return 0;
}