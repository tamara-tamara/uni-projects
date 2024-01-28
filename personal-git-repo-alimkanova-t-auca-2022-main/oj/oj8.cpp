//
// Created by User on 29.09.2023.
//
#include <vector>
#include "iostream"

using namespace std;
struct PeakData {
    vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int> &v) {
    PeakData result;
    int n = (int) v.size();
    if (n == 0) {
        return result;
    }
    int max = -10000;
    int peak = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] > max) {
            peak = i;
        } else if (v[i] < max && peak > 0) {
            result.peaks.push_back(max);
            result.pos.push_back(peak);
            peak = 0;
        }
        max = v[i];
    }
    return result;
}

int main() {
    vector<int> arr = {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3};
    PeakData res = pick_peaks(arr);
    for (int i = 0; i < res.pos.size(); ++i) {
        cout << res.pos[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < res.peaks.size(); ++i) {
        cout << res.peaks[i] << " ";
    }

    return 0;
}

