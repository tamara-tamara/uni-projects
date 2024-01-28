//
// Created by User on 23.09.2023.
//
#include "iostream"
#include "vector"

using namespace std;

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = 1; j < numbers.size(); ++j) {
            if (numbers.at(i) + numbers.at(j) == target) {
                return {i, j};
            }
        }
    }
    return {0, 0};
}

int main() {
    vector<int> num = {1, 2, 3};
    int target = 4;
    cout << two_sum(num, target).first << two_sum(num, target).second << endl;

    return 0;
}