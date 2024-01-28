
#include "BigInt.h"
#include "BigIntException.h"
#include "string"

using namespace std;

/**
 * @brief Helper function to delete leading zeros. It is used to return correct result with no leading zeros.
 * @param input_string
 * @return string
 */
string BigInt::delete_zeros(string &input_string) {
    if (input_string == "0") {                       /// if input = 0, return input
        return input_string;
    }
    if (input_string[0] == '-') {              ///if input is negative, checking zeros from the next index
        int iter = 1;
        while (input_string[iter] == '0') {           ///while loop for finding leading zeros and erasing it
            input_string.erase(iter, 1);
        }
        return input_string;
    } else if (input_string[0] == '0') {        /// if input is positive, then checking zeros from 0 index
        int iter = 0;
        while (input_string[iter] == '0') {           ///while loop for finding leading zeros and erasing it
            input_string.erase(iter, 1);
        }
        return input_string;
    }
    return input_string;
}

/**
 * @brief Boolean method to check, if string is in a appropriate format.
 * @param str
 * @return bool
 */
bool BigInt::is_bigint(string str) {
    if (str.empty()) {
        return true;
    }
    if (str.find(' ') != string::npos) {      ///There should not be spaces between numbers
        return false;
    }
    if (str[0] == '-') {                          /// if string is negative, erasing it for next loop checking
        str.erase(0, 1);
    }
    for (char i: str) {
        if (!isdigit(i)) {         ///Each element of BigInt should be a digit
            return false;
        }
    }
    return true;
}

/**
 * @brief Method for erasing leading and ending spaces. It is used to return BigInt in a appropriate format.
 * @param input_string
 * @return string
 */
string BigInt::delete_leading_and_last_spaces(string &input_string) {
    if (input_string[0] == ' ') {
        int iter = 0;
        while (input_string[iter] == ' ') {                /// erasing leading spaces
            input_string.erase(iter, 1);
        }

    }
    int iter = (int) input_string.length() - 1;
    while (input_string[iter] == ' ') {
        input_string.erase(iter, 1);      /// erasing ending spaces
    }
    return input_string;
}


/**
 * @brief Method to convert string to BigInt.
 * @param s
 * @return BigInt
 */
BigInt BigInt::to_bigint(string s) {
    BigInt res;
    res.my_str = s;
    return res;
}