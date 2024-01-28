//
// Created by User on 24.09.2023.
//

#include "iostream"
#include "vector"
#include "numeric"

using namespace std;

int solve(std::vector<int> v) {
    int pairs_counter = 0;
    int n = (int) v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (v[i] + v[j] == 0) {
                pairs_counter++;
            }
        }
    }
    int sum = std::accumulate(v.begin(), v.end(), 0);
    int den = (int) (v.size() - (2 * pairs_counter));
    int result = (int) (sum / den);
    return result;
}

int main() {
    vector<int> n = {-110, 110, -38, -38, -62, 62, -38, -38, -38};
    cout << solve(n) << endl;
    return 0;
}