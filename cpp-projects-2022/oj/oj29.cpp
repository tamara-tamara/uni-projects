
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string str;
    set<string> words;
    string result;

    while (getline(cin, str)) {
        if (str.empty()) {
            result = "";
        }

        for (int i = 0; i < str.size(); ++i) {
            char c = tolower(str[i]);

            if (isalpha(c)) {
                result += c;
            } else if (str[i] == '-' && i + 1 != str.size()) {
                result += str[i];
            } else if (!result.empty() && str[i] != '-') {
                words.insert(result);
                result = "";
            }
        }
        if (!result.empty() && str[str.length() - 1] != '-') {
            words.insert(result);
            result = "";
        }
    }


    for (const auto &word: words) {
        cout << word << endl;
    }

    return 0;
}