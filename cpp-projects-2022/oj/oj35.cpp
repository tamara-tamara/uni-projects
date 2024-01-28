#include "iostream"
#include "string"
#include "cmath"
#include <cstdint>

using namespace std;

string ip_to_binary(string ip) {
    int decimal = stoi(ip);
    string result;
    while (decimal > 0) {
        result += to_string(decimal % 2);
        decimal /= 2;
    }
    string res;
    int size = result.length();
    for (int i = result.length() - 1; i > -1; --i) {
        while (size != 8) {
            res += "0";
            size++;
        }
        res += result[i];
    }
    return res;
}

uint32_t ip_to_int32(const std::string &ip) {
    string temp;
    string result;
    int counter = 0;
    for (int i = 0; i < ip.length(); ++i) {
        if (ip[i] == '.') {
            result += ip_to_binary(temp);
            counter++;

            temp = "";
        } else if (counter == 3) {
            string b = ip.substr(i, ip.length() - i);
            result += ip_to_binary(b);
            break;
        } else {
            temp += ip[i];
        }
    }
    string res = result;

    uint32_t sum = 0;
    int pos = 0;
    for (int i = res.length() - 1; i > -1; --i) {
        if (res[i] == '1') {
            if (pos == 31) {
                uint32_t ans = 1;
                int two = 2;
                while (pos > 0) {
                    int bit = (pos & 1);
                    if (bit) {
                        ans = ans * two;
                    }
                    two = two * two;
                    pos = pos >> 1;
                }

                sum += ans;
            } else {
                sum += (uint32_t) pow(2, pos);
            }
        }
        pos++;
    }
    return sum;
}

int main() {
    uint32_t res = ip_to_int32("128.114.17.104");
    //string res = ip_to_binary("1");

    cout << res;
    return 0;
}