//
// Created by User on 19.10.2023.
//

#include "iostream"
#include "string"
#include "vector"

using namespace std;

int main() {
    int n;
    vector<string> names;
    string s;
    cin >> n;
    int index = 0;
    cin.ignore();
    while (n != 0) {
        getline(cin, s);
        if (s.size() > 4) {
            int temp = (int) s.find(' ');
            string con = s.substr(temp + 1, s.size());
            names.push_back(con);
            index++;
        } else if (s == "Kick") {
            if (index > 0) {
                names.erase(names.begin() + index - 1);
                index--;
            }
        } else if (s == "Test") {
            if ((index - 1) < 0) {
                cout << "Not in a dream" << endl;
            } else {
                cout << names[index - 1] << endl;
            }
        }

        n--;
    }
    return 0;
}