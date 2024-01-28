//
// Created by User on 29.09.2023.
//
#include <vector>
#include "iostream"

using namespace std;

std::vector<int> move_zeroes(const std::vector<int> &input) {
    std::vector<int> result;
    int zero_counter = 0;
    int s = (int) input.size();
    for (int i = 0; i < s; ++i) {
        if (input[i] != 0) {
            result.push_back(input.at(i));
        } else {
            zero_counter++;
        }
    }
    for (int i = 0; i < zero_counter; ++i) {
        result.push_back(0);
    }
    return result;
}

int main() {
    vector<int> move_zeros = {1, 0, 1, 2, 0, 1, 3};
    vector<int> res = move_zeroes(move_zeros);
    int n = (int) move_zeros.size();
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;

}