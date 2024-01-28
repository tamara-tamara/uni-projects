//
// Created by User on 19.10.2023.
//
#include "iostream"
#include "vector"

using namespace std;

std::vector<int> deleteNth(std::vector<int> arr, int n) {
    vector<int> res;
    int occur[100] = {0};
    for (int i = 0; i < (int) arr.size(); ++i) {
        occur[arr[i]]++;
        if (occur[arr[i]] <= n) {
            res.push_back(arr[i]);
        }
    }
    return res;
}

int main() {
    vector<int> res = deleteNth({1, 1, 3, 3, 7, 2, 2, 2, 2}, 3);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}