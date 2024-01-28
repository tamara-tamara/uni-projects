//
// Created by User on 19.10.2023.
//

#include "iostream"
#include "string"

using namespace std;

int countDeafRats(const std::string &town) {
    int deaf_m = 0;
    string pied_paper;
    string res;
    for (int i = 0; i < town.size(); ++i) {
        char temp = (char) town[i];
        if (temp != ' ') {
            res += temp;
        }
    }
    int size = (int) res.size();
    int pos_of_p = (int) res.find('P');
    if (pos_of_p == 0) {
        for (int i = 1; i < size; i += 2) {
            char temp = res[i];
            if (temp != 'O') {
                deaf_m++;
            }
        }
    } else if (pos_of_p == (size - 1)) {
        for (int i = 0; i < (size - 1); i += 2) {
            char temp = res[i];
            if (temp != '~') {
                deaf_m++;
            }
        }
    } else {
        string first_part = res.substr(0, ((pos_of_p - 1)));
        string second_part = res.substr(((pos_of_p + 1)), size);
        for (int i = 0; i < first_part.size(); i += 2) {
            char temp = first_part[i];
            if (temp != '~') {
                deaf_m++;
            }
        }
        for (int i = 1; i < second_part.size(); i += 2) {
            char temp = second_part[i];
            if (temp != '~') {
                deaf_m++;
            }
        }

    }
    return deaf_m;
}

int main() {
    int res = countDeafRats("~O~O~O~O~O~O~O~O~O~O~O~O~O~O~O  ~O~O~O~OO~O~~OPO~O~O~~OO~O~O~O~O~O~O~O~");
    cout << res;
    return 0;
}