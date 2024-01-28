
#include "iostream"
#include "vector"

using namespace std;
int temp_sum = 0;
vector<int> res_v;

void find_track(vector<int> vec, vector<int> tracks, int pos, int sum, int input, int track) {
    if (pos >= track) {
        if (sum > temp_sum) {
            res_v.clear();
            temp_sum = sum;
            for (int i = 0; i < tracks.size(); ++i) {
                res_v.push_back(tracks[i]);
            }
        } else if (sum == temp_sum && tracks.size() > res_v.size()) {
            res_v.clear();
            temp_sum = sum;
            for (int i = 0; i < tracks.size(); ++i) {
                res_v.push_back(tracks[i]);
            }
        }
        return;
    }
    find_track(vec, tracks, pos + 1, sum, input, track);
    if (sum + vec[pos] <= input) {
        tracks.push_back(vec[pos]);
        find_track(vec, tracks, pos + 1, sum + vec[pos], input, track);
        tracks.pop_back();
    }
}

int main() {
    int input;
    int track;
    while (cin >> input >> track) {
        vector<int> best(track);
        for (int i = 0; i < track; ++i) {
            cin >> best[i];
        }
        vector<int> tracks;
        temp_sum = 0;
        res_v.clear();
        find_track(best, tracks, 0, 0, input, track);
        for (int i = 0; i < res_v.size(); ++i) {
            cout << res_v[i] << " ";
        }
        cout << "sum:" << temp_sum << endl;
    }
    return 0;
}