#include "iostream"
#include "vector"
#include "map"

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        map<int, int> list;
        for (int j = 0; j < a; ++j) {
            int input;
            cin >> input;
            list[input]++;
        }
        for (int j = 0; j < b; ++j) {
            int input;
            cin >> input;
            list[input]--;
        }
        int res = 0;
        for (auto num: list) {
            res = res + abs(num.second);
        }
        cout << res << endl;
    }
    return 0;
}