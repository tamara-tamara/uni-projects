//
// Created by User on 12.10.2023.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    int num_of_s;
    int num_of_play;
    cin >> num_of_s >> num_of_play;
    if (num_of_s == 1 && num_of_play == 2) {
        cout << "2";
        return 0;
    }
    vector<int> nums(num_of_play, 0);
    vector<int> players(num_of_play);

    for (int i = 0; i < num_of_play; ++i) {
        players[i] = i + 1;
    }
    int pos = 0;
    int eliminated = 0;

    while (eliminated < num_of_play - 1) {
        for (int i = 0; i < num_of_s; ++i) {
            do {
                pos = (pos + 1) % num_of_play;
            } while (nums[pos] != 0);
        }
        if (nums[pos] == 0) {
            nums[pos] = 1;
            eliminated++;
        }
        do {
            pos = (pos + 1) % num_of_play;
        } while (nums[pos] != 0);
    }
    for (int i = 0; i < num_of_play; ++i) {
        if (nums[i] == 0) {
            cout << players[i];
            break;
        }
    }
    return 0;
}