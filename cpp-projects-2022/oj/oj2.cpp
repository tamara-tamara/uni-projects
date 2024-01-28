//
// Created by User on 23.09.2023.
//

#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int> > matrixAddition(std::vector<std::vector<int> > a, std::vector<std::vector<int> > b) {
    int n = a.size();
    int m = a[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] += b[i][j];
        }
    }
    return a;
}

int main() {
    vector<vector<int> > a = {{1, 2, 3},
                              {3, 2, 1},
                              {1, 1, 1}};
    vector<vector<int> > b = {{2, 2, 1},
                              {3, 2, 3},
                              {1, 1, 3}};
    vector<vector<int>> res = matrixAddition(a, b);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[0].size(); ++j) {
            cout << res[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}