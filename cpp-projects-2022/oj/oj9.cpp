//
// Created by User on 30.09.2023.
//
#include "iostream"
#include "vector"

using namespace std;

int josephusSurvivor(int n, int k) {
    std::vector<int> num;
    for (int i = 0; i < n; ++i) {
        num.push_back(i + 1);
    }
    int unlucky_pos = k;
    while (num.size() != 1) {
        if (unlucky_pos > num.size()) {
            while (unlucky_pos > num.size()) {
                unlucky_pos -= num.size();
            }
        }
        num.erase(num.begin() + unlucky_pos - 1);
        unlucky_pos += k - 1;
    }
    return num[0];
}

int main() {
    int res = josephusSurvivor(7, 3);
    cout << res;
    return 0;
}