//
// Created by User on 01.10.2023.
//
#include <vector>
#include "iostream"

using namespace std;

std::vector<std::vector<int>> create_spiral(int n) {
    if (n<1 ){
        return {};
    }
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
    int index = 0;
    int col = 0;
    int row = 0;
    int num = 1;
    while ((num - 1) != n * n) {
        for (int j = row; j < (n - index); ++j) {
            result[col][j] = num;
            row++;
            num++;
        }
        col++;
        row--;
        for (int j = row; col <= j; col++) {
            result[col][j] = num;
            num++;
        }
        col--;
        row--;
        for (int j = row; j >= index; j--) {
            result[col][j] = num;
            num++;
            row--;
        }
        col--;
        row++;
        for (int j = row; col > j; col--) {
            result[col][j] = num;
            num++;
        }
        col++;
        row++;
        index++;
    }
    return result;
}

int main() {
    vector<vector<int>> arr = create_spiral(5);
    for (int i = 0; i < arr[0].size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            cout << arr[i][j] << " ";
        }
    }
    return 0;
}