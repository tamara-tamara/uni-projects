//
// Created by User on 13.10.2023.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    int num_of_test;
    int size_of_a;
    cin >> num_of_test;
    int sum;
    for (int i = 0; i < num_of_test; ++i) {
        cin >> size_of_a;
        vector<int> nums;
        for (int j = 0; j < size_of_a; ++j) {
            int temp;
            cin >> temp;
            nums.push_back(temp);
            sum = 0;
        }

        for (int j = 1; j < size_of_a; ++j) {
            for (int k = 0; k < j; ++k) {
                if (nums[k] <= nums[j]) {
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}