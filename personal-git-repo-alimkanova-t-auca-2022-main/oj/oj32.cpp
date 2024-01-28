#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

string binary_represent(int n) {
    string result;
    while (n / 2 != 0) {
        int temp = n % 2;
        result += to_string(temp);
        n /= 2;
    }
    reverse(result.begin(), result.end());
    result = '1' + result;
    return result;
}

std::string whitespace_number(int n) {
    if (n == 0) {
        return " \n";
    }
    string num = to_string(n);
    string result;
    if (num[0] == '-') {
        result += "\t";
    } else {
        result += " ";
    }
    num = to_string(abs(n));
    string bin = binary_represent(stoi(num));
    for (int i = 0; i < bin.size(); ++i) {
        if (bin[i] == '0') {
            result += " ";
        } else {
            result += "\t";
        }
    }
    result += "\n";
    return result;
}

int main() {
    string a = whitespace_number(1);
    std::cout << a;
    return 0;
}