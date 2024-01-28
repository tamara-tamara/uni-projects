//
// Created by User on 29.09.2023.
//
#include <vector>
#include "iostream"

using namespace std;

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
    std::vector<int> result;
    int rowS = snail_map.size();
    int columnS = snail_map[0].size();
    int index = 0;
    int col = 0;
    int row = 0;
    while (result.size() != rowS * columnS) {
        for (int j = row; j < (rowS - index); ++j) {
            result.push_back(snail_map[col][j]);
            row++;
        }
        col++;
        row--;
        for (int j = row; col <= j; col++) {
            result.push_back(snail_map[col][j]);
        }
        col--;
        row--;
        for (int j = row; j >= index; j--) {
            result.push_back(snail_map[col][j]);
            row--;
        }
        col--;
        row++;
        for (int j = row; col > j; col--) {
            result.push_back(snail_map[col][j]);
        }
        col++;
        row++;
        index++;
    }
    return result;
}

int main() {
    vector<vector<int>> array = {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}};
    vector<int> res = snail(array);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}