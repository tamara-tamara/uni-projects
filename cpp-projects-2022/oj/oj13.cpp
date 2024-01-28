//
// Created by User on 05.10.2023.
//
#include "string"
#include "iostream"


std::string incrementString(const std::string &str) {
    std::string res;
    int num_of_digits = 0;
    bool has_digit = false;

    for (int i = str.size() - 1; i >= 0; --i) {
        if (isdigit(str[i])) {
            if (!has_digit) {
                num_of_digits = 1;
                has_digit = true;
            } else {
                num_of_digits++;
            }
        } else {
            break;
        }
    }

    if (!has_digit) {
        return str + "1";
    }

    int num = std::stoi(str.substr(str.size() - num_of_digits)) + 1;
    std::string numbers = std::to_string(num);
    while (numbers.size() < num_of_digits) {
        numbers = "0" + numbers;
    }
    res = str.substr(0, str.size() - num_of_digits);

    return res + numbers;
}

int main() {
    std::string n = incrementString("foobar23");
    std::cout << n << std::endl;
    return 0;
}