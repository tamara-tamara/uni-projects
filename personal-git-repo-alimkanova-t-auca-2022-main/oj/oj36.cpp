#include <string>
#include "cmath"
#include <cstdint>
#include "iostream"
#include "vector"
#include "bitset"

using namespace std;

string int32_to_binary(uint32_t num) {
    return bitset<32>(num).to_string();
}

uint32_t bin_to_dec(const string &bin) {
    bitset<8> bitset(bin);
    return static_cast<uint8_t>(bitset.to_ulong());
}

std::string uint32_to_ip(uint32_t ip) {
    string bin_code = int32_to_binary(ip);
    string result;
    string sub_s;
    int counter = 0;
    for (int i = 0; i < bin_code.size(); ++i) {
        if (i + 1 == bin_code.size()) {
            sub_s += bin_code[i];
            uint32_t to_dec = bin_to_dec(sub_s);
            result += to_string(to_dec);
        } else if (i % 8 == 0 && i >= 8) {
            uint32_t to_dec = bin_to_dec(sub_s);
            result += to_string(to_dec);
            if (counter <= 3) {
                result += ".";
            }
            sub_s = "";
            sub_s += bin_code[i];
            counter++;
        } else {
            sub_s += bin_code[i];
        }
    }
    return result;
}

int main() {
    string ip = uint32_to_ip(2154959208);
    cout << ip;
    return 0;
}