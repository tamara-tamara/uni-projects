
#include "map"
#include "string"
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main() {
    string str;
    string s;
    map<std::string, int> map_of_words;
    double entropy;
    double max_en;
    double relet_en;
    double let;
    while (true) {
        getline(cin, str);
        if (str == "****END_OF_INPUT****") {
            break;
        }
        if (str == "****END_OF_TEXT****") {
            entropy = 0;
            max_en = 0;
            for (auto i: map_of_words) {
                entropy += i.second * (log10(let) - log10(i.second));
            }
            max_en = log10(let);
            entropy *= 1 / let;
            relet_en = entropy / max_en * 100;

            cout << let << " " << setprecision(1) << fixed << entropy << " " << setprecision(0)
                 << fixed << round(relet_en) << endl;

            map_of_words.clear();
            let = 0;
            continue;
        }
        str += '.';
        int temp = -1;
        for (int i = 0; i < str.length(); ++i) {
            if (!(str[i] == ',' || str[i] == '.' || str[i] == '!' || str[i] == '?'
                  || str[i] == ';' || str[i] == ':' || str[i] == ')'
                  || str[i] == '(' || str[i] == '"' || str[i] == '\t'
                  || str[i] == ' ' || str[i] == '\n')) {
                if (temp == -1) {
                    temp = i;
                }
            } else {
                if (temp != -1) {
                    s = str.substr(temp, i - temp);
                    for (int i = 0; i < s.length(); i++) {
                        if (s[i] >= 'A' && s[i] <= 'Z') {
                            s[i] += 32;
                        }
                    }
                    let++;
                    map_of_words[s]++;
                }
                temp = -1;
            }

        }
    }
    return 0;
}