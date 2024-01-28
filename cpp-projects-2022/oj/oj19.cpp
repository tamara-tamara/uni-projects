//
// Created by User on 19.10.2023.
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

long queueTime(std::vector<int> customers, int n) {
    vector<long> time(n);
    for (int i = 0; i < (int) customers.size(); ++i) {
        time[0] += customers[i];
        sort(time.begin(), time.end());
    }
    long result = time[n - 1];
    return result;
}

int main() {
    long res = queueTime(vector<int>{2, 3, 10}, 2);
    cout << res;
    return 0;
}