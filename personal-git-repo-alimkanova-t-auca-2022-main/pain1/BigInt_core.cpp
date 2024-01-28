
#include  <vector>
#include "BigInt.h"
#include "BigIntException.h"
#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

/// @brief Default constructor
///@code

BigInt::BigInt() = default;
///@endcode
/** @brief Constructor that accepts string as a parameter
 * @param str
 */
///@code
BigInt::BigInt(std::string str) {
    str = delete_zeros(str);                   /// deletion of leading zeros
    str = delete_leading_and_last_spaces(str);   /// deletion of leading and last extra spaces
    //try {
    if (!is_bigint(str)) {
        throw BigIntException("Invalid format of BigInt.");
    }
//    } catch (BigIntException &b){
//        cout << b.what() << endl;
//    }
    my_str = str;
}
///@endcode
/** \brief Constructor that accepts int as a parameter
 *
 * @param num
 */
///@code
BigInt::BigInt(int num) {
    my_str = to_string(num);
}
///@endcode
/** \brief Constructor that accepts long long as a parameter
 *
 * @param l_num
 */
///@code
BigInt::BigInt(long long l_num) {
    my_str = to_string(l_num);
}
///@endcode
/** \brief Constructor that accepts BigInt as a parameter
 *
 * @param num
 */
///@code
BigInt::BigInt(const BigInt &num) {
    my_str = num.my_str;
}
///@endcode
// -------  *;-;+ functions  -------
/**
 * @brief Addition method.
 * Adding from right to left in the longest string and adding each element
from each of both strings as integer and keeping track of carry and storing the result
into new string.
 *
 * @param second
 * @return string res
 */
string BigInt::add(const string &second) {
    string first = this->my_str;
    string res;
    int sum = 0;
    int carry = 0;
    int longest = max(first.length(), second.length());   /// finding the longest string between two strings
    string shortest;
    string long_s;
    string sec_num;
    if (first.length() > second.length() || first.length() < second.length()) {  /// finding the shortest one
        if (longest != first.length()) {
            shortest = first;
            long_s = second;
        } else {
            shortest = second;
            long_s = first;
        }
        int size = longest - shortest.length();

        for (int i = 0; i < size; ++i) {          /// adding additional leading zeros to the smallest on length string
            sec_num += "0";
        }
        sec_num += shortest;
    } else {                                      /// condition where length of two string is equal
        long_s = first;
        sec_num = second;
    }
    for (int i = longest - 1; i > -1; --i) {       /// the start of addition
        char temp = long_s[i];                           /// finding the i element of each string to add
        char temp2 = sec_num[i];
        sum = (temp - '0') + (temp2 - '0') + carry;     /// addition operation of i elements of each and carry
        carry = 0;
        if (sum > 9) {                                     /// if sum>9 then carry for the next addition will be 1
            carry = 1;
        }
        res += to_string(sum % 10);
        if (i - 1 == -1 && carry !=
                           0) {                     /// if i element is the last one and carry = 1 then adding sum to the result
            sum /= 10;
            res += to_string(sum);
        }
    }
    reverse(res.begin(), res.end());           /// reversing the result as if it was stored from left to right
    return res;
}

/**
 *
 * @brief Subtract method.
 * Subtracting from right to left in the longest string and subtracting each element
from each of both strings as integer and keeping track of carry and storing the result
into new string.
 * @param second
 * @return string res
 */

string BigInt::subtract(const string &second) {
    string first = this->my_str;
    string res;
    if (first == second) {                           ///if they are equal => result = 0
        return "0";
    }
    int max = std::max(first.length(), second.length());    ///finding max length between two strings
    string shortest;
    string sec_num;
    string f_num;
    if (first.length() > second.length() ||
        first.length() < second.length()) {  /// if there is a string with min length
        if (max !=
            first.length()) {                                           /// if it is a first, then first = shortest
            shortest = first;
            f_num = second;
        } else {                                                             /// if it is a second, then second = shortest
            shortest = second;
            f_num = first;
        }
        int size = max - shortest.length();

        for (int i = 0; i < size; ++i) {            /// adding additional leading zeros to the smallest on length number
            sec_num += "0";
        }
        sec_num += shortest;
    } else {                                          ///if their length is equal, not changing them
        f_num = first;
        sec_num = second;
    }
    int sub = 0;
    int carry = 10;
    bool is_less = false;
    string a2;
    int temp = 0;
    for (int i = max - 1;
         i > -1; --i) {                            /// for loop for going through each i element of two strings
        char a = f_num[i];
        char b = sec_num[i];
        if ((a - '0') < (b - '0') || (a - '0') == (b - '0') && carry == 9 &&
                                     is_less) {  ///if i element of first <= i element of second and there is a carry from past subtraction
            a2 = to_string((carry + (a - '0')));
            carry = 9;
            temp = stoi(a2);
            sub = temp - (b -
                          '0');                        /// subtraction of (i element of first + carry and converted to int) and i element of second
            is_less = true;
        } else if ((a - '0') > (b - '0') || (a - '0') == (b - '0')) {   /// if i element of first >= i element of second
            if (is_less) {                                              /// if there is a carry
                a--;                                                     /// then i element of first -1
                is_less = false;
            }
            sub = (a - '0') - (b - '0');                            /// else their subtraction
        }

        res += to_string(sub);
    }
    reverse(res.begin(), res.end());                ///reversing result as if it was stored from left to right
    return res;
}

/**
 * @brief Multiplication method.
 * Naive approach of multiplication. Multiplying from right to left each possible pair
from each of both strings as integer and keeping track of carry and storing the result
into new string.
 * @param second
 * @return string result_mul
 */
string BigInt::multiply(std::string second) {
    string first = this->my_str;
    int carry = 0;
    string result_mul;
    vector<int> res(first.length() + second.length(),
                    0);      /// vector res will be used for storing multiplication and addition
    int vec_s1 = 0;
    int vec_s2 = 0;
    for (int i = (int) first.length() - 1;
         i > -1; --i) {      /// for loop for going through of each i element of strings from the end
        int n1 = (first[i] - '0');                            /// defining i element of first
        vec_s2 = 0;
        carry = 0;
        for (int j = (int) second.length() - 1; j > -1; --j) {    /// for loop for going through of each j element
            int n2 = (second[j] - '0');                            ///defining j element of second
            int mul = n1 * n2 + carry + res[vec_s1 +
                                            vec_s2];   /// multiplication of i element of first and j element if second and adding carry, previous result
            carry = mul / 10;
            res[vec_s1 + vec_s2] =
                    mul % 10;                  /// adding last element of result of multiplication to res vector
            vec_s2++;
        }
        if (carry > 0) {
            res[vec_s1 + vec_s2] += carry; /// if carry>0 adding it to vector res
        }
        vec_s1++;
    }

    int i = (int) res.size() - 1;
    while (i >= 0 && res[i] == 0) {  ///erasing leading zeros
        i--;
    }
    if (i == -1) {
        return "0";
    }
    while (i >= 0) {
        result_mul += std::to_string(res[i--]);  ///converting vector res to string result_mul
    }
    return result_mul;
}

//  -------- Comparing functions---------
/**
 * @brief Defining max value of two strings
 * Compares each element from left to right. The result will also depend on the signs of each string.
 * This method is used to overload compare operators.
 * @param first
 * @param second
 * @return string
 */
string BigInt::bigint_max(string first, string second) {
    bool is_max1 = false;
    bool is_max2 = false;
    bool negative = false;
    if (first[0] == '-' && second[0] == '-') {      /// if both are negative
        negative = true;
        first.erase(0, 1);               /// erasing their signs
        second.erase(0, 1);
    } else if (first[0] == '-') {                /// if first is negative
        return second;                             ///max will be the second positive
    } else if (second[0] == '-') {               /// if second is negative
        return first;                            /// max will be the first positive
    }
    if (first.length() == second.length()) {               /// if their length is equal
        for (int i = 0;
             i < first.length(); ++i) {           /// for loop for going through of each i element from left to right
            if (first[i] != second[i]) {                   /// comparing i elements
                if (first[i] > second[i]) {
                    is_max1 = true;
                } else {
                    is_max2 = true;
                }
                break;
            }
        }
    } else if (first.length() >
               second.length()) {         /// if length of first >, then first is max, but will be additionally checked for its sign
        is_max1 = true;
    } else {                                  /// if length of second >, then second is max, but will be additionally checked for its sign
        is_max2 = true;
    }
    if (negative) {                       /// if they are both negative
        if (is_max1) {                         /// if first's value was max, then result = '-' +second
            return ("-" + second);
        } else {                            /// if second' value was max, then result = '-' + first
            return ("-" + first);
        }
    } else {                             /// if they are both positive
        if (is_max1) {
            return first;               /// if first's value is max, then first = max
        } else {
            return second;              /// if second's value is max, then second = max
        }
    }
}

/**
 * @brief Defining minimum method. It was constructed according to bigint_max method.
 * It is used to overload compare operators.
 * @param first
 * @param second
 * @return string
 */
string BigInt::bigint_min(string first, string second) {
    string max = bigint_max(first, second);         ///finding max value of two strings
    if (max == first) {                           /// if first = max
        return second;                           /// then min = second
    } else
        return first;                           /// else min = first
}

/**
 * @brief Boolean is_max method defines max value between two strings.
 * It is constructed by using bigint_max method, and it is used to overload compare operators.
 * @param first
 * @param second
 * @return bool
 */
bool BigInt::is_max(const std::string &first, std::string second) {
    if (first == bigint_max(first, second)) { /// if first is max, return true
        return true;
    } else
        return false;                           /// else false
}

/**
 * @brief Boolean is_min method defines max value between two strings.
 * It is constructed by using bigint_min method, and it is used to overload compare operators.
 * @param first
 * @param second
 * @return bool
 */
bool BigInt::is_min(const std::string &first, std::string second) {
    if (first == bigint_min(first, second)) {
        return true;
    } else
        return false;
}

/**
 * @brief Boolean is_max_not_equal method is used to define strict equality.
 * It is used to overload compare operators.
 * @param first
 * @param second
 * @return bool
 */
bool BigInt::is_max_and_not_equal(string first, string second) {
    if (first == second) {                                     /// if two strings equal => false
        return false;
    }
    if (first == bigint_max(first, second)) {               /// if first = max => true
        return true;
    } else                                                   /// else false
        return false;
}

/**
 * @brief Boolean is_min_not_equal method is used to define strict equality.
 * It is used to overload compare operators.
 * @param first
 * @param second
 * @return bool
 */
bool BigInt::is_min_and_not_equal(const string &first, const string &second) {
    if (first == second) {                                      /// if two string equal => false
        return false;
    }
    if (first == bigint_min(first, second)) {                   /// if first = max, but not equal => true
        return true;
    } else                                                     /// else false
        return false;
}

//---- Operators overloading ------
/**
 * @brief Overloading of output operator.
 * @param os
 * @param n
 * @return ostream
 */
///@code
ostream &operator<<(ostream &os, const BigInt &n) {
    os << n.my_str;
    return os;
}
///@endcode
/**
 * @brief Overloading of input operator.
 * @param os
 * @param n
 * @return ostream
 */
///@code
istream &operator>>(istream &os, BigInt &n) {
    os >> n.my_str;
    return os;
}
///@endcode
/**
 * @brief Overloading of + operator
 * @param BigInt first
 * @param BigInt second
 * @return BigInt
 */
///@code
BigInt operator+(const BigInt &other) {
    BigInt res;
    res = res + other;        ///using overloaded operator + for two BigInt
    return res;
}
///@endcode
/**
 * @brief Overloading of + operator. Erasing '-' sign of negative numbers, and returning positive or negative result
 * according to the signs of each BigInt.
 * @param BigInt first
 * @param BigInt second
 * @return BigInt res
 */
///@code
BigInt operator+(const BigInt &first, const BigInt &second) {
    BigInt res;
    string first_s = first.my_str;
    string second_s = second.my_str;
    if (first.my_str[0] == '-' && second.my_str[0] == '-') {    /// if first and second are both negative
        first_s = first_s.erase(0, 1);                    /// erase '-' sign
        second_s = second_s.erase(0, 1);
        BigInt f_bigint = BigInt::to_bigint(first_s);
        res = '-' + f_bigint.add(second_s);                 /// '-' + their addition
    } else if (first.my_str[0] == '-') {                         /// if first is negative
        first_s = first_s.erase(0, 1);                     /// then erase '-' sign
        if (first_s == second_s) {
            return 0;
        }
        string max = BigInt::bigint_max(first_s, second.my_str);     ///finding max value between two string
        string min = BigInt::bigint_min(first_s, second.my_str);     /// finding min value between them
        BigInt temp = BigInt::to_bigint(
                max);                                 /// by using private to_bigint method we change string to BigInt
        BigInt temp2 = BigInt::to_bigint(min);
        if (max == first_s) {                                                   /// if negative first's value was max
            res = '-' + temp.subtract(temp2.my_str);                     /// then the res = '-' and subtraction
        } else {
            res = temp.subtract(temp2.my_str);                           /// if positive second was max
        }                                                                      /// then result = their subtraction
    } else if (second.my_str[0] == '-') {                                      /// if second is negative
        if (first_s == second_s) {
            return 0;
        }
        second_s = second_s.erase(0, 1);
        string max = BigInt::bigint_max(first.my_str, second_s);            /// finding max value
        string min = BigInt::bigint_min(first.my_str, second_s);
        BigInt temp = BigInt::to_bigint(max);
        BigInt temp2 = BigInt::to_bigint(min);
        if (max ==
            second_s) {                                                          /// if negative second's value was max
            res = '-' + temp.subtract(temp2.my_str);                             /// res = '-' their subtraction
        } else {
            res = temp.subtract(
                    temp2.my_str);                                   /// if positive first was max then res = subtraction
        }
    } else {
        BigInt f = BigInt::to_bigint(first_s);                                  /// if they are both positive
        res = f.add(second.my_str);                                            /// res = their addition
    }
    return res;
}
///@endcode
/**
 * @brief Operator + overloading.
 * @param BigInt first
 * @param int second
 * @return BigInt
 */
///@code
BigInt operator+(const BigInt &first, int second) {
    BigInt temp(second);                          ///converting int to BigInt to use overloaded + for two BigInt
    return first + temp;
}
///@endcode
/**
 * @brief Operator + overloading
 * @param int second
 * @param BigInt first
 * @return BigInt
 */
///@code
BigInt operator+(int second, const BigInt &first) {
    BigInt temp(second);                         ///converting int to BigInt to use overloaded + for two BigInt
    return first + temp;
}
///@endcode
/**
 * @brief Operator + overloading
 * @param BigInt first
 * @param long long int second
 * @return BigInt
 */
///@code
BigInt operator+(const BigInt &first, long long int second) {
    BigInt temp(
            second);                         ///converting long long int to BigInt to use overloaded + for two BigInt
    return first + temp;
}
///@endcode
/**
 * @brief Overloading - operator
 * @param BigInt other
 * @return BigInt
 */
///@code
BigInt operator-(const BigInt &other) {
    BigInt res;
    res = other - res;
    return res;
}
///@endcode
/**
 * @brief Overloading - operator.
 * Erasing '-' sign of negative numbers, and returning positive or negative result
 * according to the signs of each BigInt.
 * @param BigInt first
 * @param BigInt second
 * @return BigInt res
 */
///@code
BigInt operator-(const BigInt &first, const BigInt &second) {
    BigInt res;
    string first_s = first.my_str;
    string second_s = second.my_str;
    if (first.my_str[0] == '-' && second.my_str[0] == '-') {          /// if first and second are both negative
        first_s = first_s.erase(0, 1);                         /// erase '-' sign
        second_s = second_s.erase(0, 1);
        if (first_s ==
            second_s) {                                     /// if their value is equal => their subtraction is equal to zero
            return 0;
        }
        string max = BigInt::bigint_max(first_s, second_s);     /// finding max and min values
        string min = BigInt::bigint_min(first_s, second_s);
        BigInt temp = BigInt::to_bigint(
                max);                            /// converting both string to BigInt by using to_bigint helper method
        BigInt temp2 = BigInt::to_bigint(min);
        if (max == first_s) {                                            /// if max = negative first
            res = '-' + temp.subtract(temp2.my_str);              /// then res = '-' their subtraction
        } else {
            res = temp.subtract(
                    temp2.my_str);                    /// if max = negative second, which in subtraction will become positive (-(-a))=+a
        }                                                                 ///  then res = their subtraction

    } else if (first.my_str[0] == '-') {                                  /// if first is negative
        first_s = first_s.erase(0, 1);                              /// erasing '-' sign
        BigInt f_bigint = BigInt::to_bigint(first_s);
        res = "-" + f_bigint.add(second_s);                        /// res = '-' and their addition
    } else if (second.my_str[0] == '-') {                                 /// if second is negative
        second_s = second_s.erase(0, 1);                              /// erasing '-' sign
        BigInt s_bigint = BigInt::to_bigint(second_s);
        res = s_bigint.add(first_s);                                  /// res = their addition, because (-(-a))=+a
    } else {                                                               ///if they are positive
        BigInt f = BigInt::to_bigint(first_s);
        string max = BigInt::bigint_max(first_s, second_s);        /// finding max and min values
        string min = BigInt::bigint_min(first_s, second_s);
        if (first_s == min && second_s == max && min != max) {            /// if second is max
            string neg_sec = "-" + second_s;
            res = first + neg_sec;                                         /// res = first+(-second)
        } else {
            res = f.subtract(second_s);                           /// res = their subtraction
        }
    }
    return res;
}
///@endcode
/**
 * @brief Overloading - operator
 * @param BigInt first
 * @param int second
 * @return BigInt res
 */
///@code
BigInt operator-(const BigInt &first, int second) {
    BigInt temp(second);                         ///converting int to BigInt to use overloaded - for two BigInt
    return first - temp;
}
///@endcode
/**
 * @brief Overloading - operator
 * @param int second
 * @param BigInt first
 * @return BigInt res
 */
///@code
BigInt operator-(const int &second, const BigInt &first) {
    BigInt temp(second);                              ///converting int to BigInt to use overloaded - for two BigInt
    return temp - first;
}
///@endcode
/**
 * @brief Overloading - operator
 * @param BigInt first
 * @param long long int second
 * @return BigInt res
 */
///@code
BigInt operator-(const BigInt &first, long long int second) {
    BigInt temp(
            second);                              ///converting long long int to BigInt to use overloaded - for two BigInt
    return first + temp;
}
///@endcode
/**
 * @brief Overloading * operator.
 * Erasing '-' sign of negative numbers, and returning positive or negative result
 * according to the signs of each BigInt.
 * @param BigInt second
 * @return BigInt res
 * @code
 */
BigInt BigInt::operator*(const BigInt &second) const {
    BigInt res;
    BigInt first = *this;
    string first_s = first.my_str;
    string second_s = second.my_str;
    if (first_s == "0" || second_s == "0") {             /// if one of them equals to 0, then result = 0
        return 0;
    }
    if (first.my_str[0] == '-' && second.my_str[0] == '-') {            /// if first and second are both negative
        first_s = first_s.erase(0, 1);                          /// erase '-' sign
        second_s = second_s.erase(0, 1);
        BigInt f_bigint = BigInt::to_bigint(first_s);
        res = f_bigint.multiply(second_s);                         /// result = their multiplication
    } else if (first.my_str[0] == '-') {                                   /// if first is negative
        first_s = first_s.erase(0, 1);                              /// then erase '-' sign
        BigInt f_bigint = BigInt::to_bigint(first_s);
        res = "-" + f_bigint.multiply(second_s);                     /// result = '-' their multiplication
    } else if (second.my_str[0] == '-') {                                  /// if second is negative
        second_s = second_s.erase(0, 1);                          /// then erase '-' sign
        BigInt s_bigint = BigInt::to_bigint(second_s);
        res = "-" + s_bigint.multiply(first_s);                   /// result = '-' their multiplication
    } else {                                                             /// if both are positive
        BigInt f = BigInt::to_bigint(first_s);
        res = f.multiply(second_s);                              /// result = their multiplication
    }
    return res;
}
///@endcode
/**
 * @brief Overloading * operator
 * @param BigInt first
 * @param int second
 * @return BigInt
 */
///@code
BigInt operator*(const BigInt &first, const int &second) {
    BigInt temp(
            second);                                     ///converting int to BigInt to use overloaded * for two BigInt
    return first * temp;
}
///@endcode
/**
 * @brief Overloading * operator
 * @param int second
 * @param BigInt first
 * @return BigInt
 */
///@code
BigInt operator*(const int &second, const BigInt &first) {
    BigInt temp(second);                                 ///converting int to BigInt to use overloaded * for two BigInt
    return first * temp;
}
///@endcode
/**
 * @brief Overloading * operator
 * @param BigInt first
 * @param long long int second
 * @return BigInt
 */
///@code
BigInt operator*(const BigInt &first, long long int second) {
    BigInt temp(
            second);                                  ///converting long long int to BigInt to use overloaded * for two BigInt
    return first * temp;
}
///@endcode
/**
 * @brief Overloading * operator
 * @param long long int second
 * @param BigInt first
 * @return BigInt
 */
///@code
BigInt operator*(long long int second, const BigInt &first) {
    BigInt temp(
            second);                                   ///converting long long int to BigInt to use overloaded * for two BigInt
    return temp * first;
}
///@endcode
/**
 * @brief Overloading * operator
 * @param BigInt other
 * @return BigInt
 * @code
 */

BigInt operator*(const BigInt &other) {
    BigInt res;
    res = res * other;                       ///using overloaded * operator for two BigInt
    return res;
}
///@endcode