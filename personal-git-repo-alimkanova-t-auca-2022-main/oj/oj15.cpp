//
// Created by User on 11.10.2023.
//
#include <algorithm>
#include "iostream"
#include "string"

using namespace std;

long nextBigger(long n) {
    string str = to_string(n);
    long num = -1;
    bool has_next_bigger = false;
    for (int i = (int) (str.length() - 2); i > -1; --i) {
        if (str[i] < str[i + 1]) {
            for (int j = (int) (str.length() - 1); j > i; --j) {
                if (str[j] > str[i]) {
                    swap(str[i], str[j]);
                    reverse(str.begin() + i + 1, str.end());
                    num = stol(str);
                    has_next_bigger = true;
                    break;
                }
            }
            if (has_next_bigger) {
                break;
            }
        }
    }

    return num;
}

int main() {
    long num = nextBigger(10990);
    cout << num << endl;
    return 0;
}