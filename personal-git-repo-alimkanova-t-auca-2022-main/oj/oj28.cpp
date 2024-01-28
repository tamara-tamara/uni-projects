
#include "vector"
#include "string"
#include "map"
#include "iostream"

using namespace std;

class StockList {
public:
    static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories) {
        if (lstOfArt.empty() || categories.empty()) {
            return "";
        }
        map<string, int> res_books;
        for (int i = 0; i < lstOfArt.size(); ++i) {
            string str = lstOfArt[i];
            for (int j = 0; j < str.length(); ++j) {
                if (str[j] == ' ') {
                    string first_s = str.substr(0, j);
                    string second_s = str.substr(j + 1, str.length() - j);
                    int temp = stoi(second_s);
                    res_books[first_s] = temp;
                    break;
                }
            }

        }
        string result;
        for (int i = 0; i < categories.size(); ++i) {
            result += "(" + categories[i] + " : ";
            int counter = 0;
            map<string, int>::iterator it;
            for (it = res_books.begin(); it != res_books.end(); ++it) {
                if (categories[i] == it->first.substr(0, 1)) {
                    counter += it->second;
                }
            }
            result += to_string(counter) + ")";
            if (i + 1 != categories.size()) {
                result += " - ";
            }
        }
        return result;
    }
};

int main() {
    StockList stockList;
    std::vector<std::string> art = {"BBAR 150", "CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600"};
    std::vector<std::string> cd = {"A", "B", "C", "D"};
    cout << stockList.stockSummary(art, cd);

    return 0;
}