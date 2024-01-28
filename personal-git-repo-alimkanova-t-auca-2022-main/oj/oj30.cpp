#include "unordered_set"
#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"

using namespace std;

int main(){
    int t;
    cin >> t;
    int n,m ;
    for (int i = 0; i < t; ++i) {
        cin >> n >> m;
        getchar();
        vector<string> first;
        vector<string> second;
        for (int j = 0; j < n; ++j) {
            string f_lang;
            getline(cin, f_lang);
            first.push_back(f_lang);
        }

        for (int j = 0; j < m; ++j) {
            string s_lang;
            getline(cin, s_lang);
            second.push_back(s_lang);
        }
        unordered_map<string, int> words;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                string temp = first[j] + second[k];
                words[temp]++;
            }
        }
        cout << "Case " << i+1 <<": " << words.size() << endl;
    }
    return 0;
}