
#include  <vector>
#include "BigInt.h"
#include "BigIntException.h"
#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

/**
 * @brief Division function.Divide using naive approach. Divide by finding number [0-9]
 * which multiplication to divisor <= part of dividend or to whole dividend.
 * @param second
 * @return string
 */
string BigInt::divide(const string &second) {
    string res;
    string first = this->my_str;
    if (first == second) {                   /// if dividend = divisor return 1
        return "1";
    } else {
        if (second == "1") {                 /// if divisor =1 return dividend
            return first;
        }
        if (to_bigint(second) > to_bigint(first)) {    /// if divisor > dividend , return 0
            return "0";
        }
        BigInt temp;
        bool is_left = false;
        bool is_less = false;
        bool is_next_added = false;
        bool is_not_empty = false;
        int pos_res = 0;
        BigInt numerator = to_bigint(first);
        string f_copy = first;
        BigInt denum = to_bigint(second);
        string temp_str;
        for (int i = 0; i < first.length(); ++i) {
            if (is_less) {                       /// previous elements was less than divisor and will be inserted to the next element
                temp_str += f_copy[i];          ///adding the previous element
                is_less = false;
                is_next_added = true;
            } else {
                temp_str = f_copy[i];  /// storing i element of dividend
            }
            if (is_left) {                        /// if subtract of the previous element !=0
                temp_str.insert(0, temp.my_str);
                is_left = false;
                is_next_added = true;
            }
            if (temp_str < denum && is_next_added &&
                is_not_empty) { ///if i element(s) of dividend < divisor and result is not empty
                res += "0";
                pos_res++;
                is_next_added = false;
                is_less = true;
            } else if (temp_str >= denum) {                           /// if i element(s) of dividend >= divisor
                for (int j = 1; j < 10; ++j) {                              ///for loop for finding quotient j from 0-9
                    if (j * denum <= temp_str && (j + 1) * denum >
                                                 temp_str) {   /// if j*divisor <= i element(s) of dividend, and multiplication with next j > i element(s)
                        res += to_string(j);
                        is_not_empty = true;                            /// quotient is not empty
                        pos_res++;                                       ///increasing position of storing quotient
                        break;
                    }
                }
                int pos = pos_res - 1;
                string res_str = to_string(res[pos] - '0');
                BigInt b_temp = to_bigint(res_str);                       ///converting quotient to BigInt
                BigInt mul = b_temp * denum;                                 /// multiplication of quotient and divisor
                BigInt sub = temp_str -
                             mul;                               /// subtraction of i element(s) of dividend and multiplication
                if (sub >
                    0) {                               /// if subtraction > 0, left result will be added to the next part of dividend
                    temp = sub;
                    is_left = true;
                }

            } else if (temp_str == "0") {       /// if element =0 && the next element !=0
                res += "0";                         /// storing zeros to quotient
                pos_res++;
                is_not_empty = true;
            } else if (temp_str < denum && i + 1 ==
                                           first.length()) {   /// if element(s) < divisor and it is the last element(s) of dividend
                res += "0";                                              ///then storing zeros
                is_not_empty = true;
                pos_res++;
            } else {
                is_less = true;
            }
        }
    }
    return res;
}

/**
 * @brief Operator / overloading.
 * @param first
 * @param second
 * @return BigInt
 */
BigInt operator/(const BigInt &first, const int &second) {
    BigInt temp(second);              /// converting int to BigInt
    return first / temp;                     /// overloaded operation between two BigInt was used
}

/**
 * @brief Operator / overloading.
 * @param first
 * @param second
 * @return BigInt
 */
BigInt operator/(const int &second, const BigInt &first) {
    BigInt temp(second);                      /// converting int to BigInt
    return temp / first;                  /// overloaded operation between two BigInt was used
}

/**
 * @brief Operator / overloading.
 * @param first
 * @param second
 * @return BigInt
 */
BigInt operator/(const BigInt &first, long long int second) {
    BigInt temp(second);                        /// converting long long int to BigInt
    return first / temp;                      /// overloaded operation between two BigInt was used
}

/**
 * @brief Operator / overloading.
 * @param first
 * @param second
 * @return BigInt
 */
BigInt operator/(long long int second, const BigInt &first) {
    BigInt temp(second);                               /// converting long long int to BigInt
    return temp / first;                              /// overloaded operation between two BigInt was used
}

/**
 * @brief Operator / overloading. Division method was used to overload it.
 *  Erasing '-' sign of negative numbers, and returning positive or negative result
 * according to the signs of each BigInt. Providing exceptions for division by zero.
 * @param first
 * @param second
 * @return BigInt
 * @code
 */

BigInt BigInt::operator/(const BigInt &other) const {
    BigInt first = *this;
    BigInt res;
    string first_s = first.my_str;
    string second_s = other.my_str;
    //try {
    if (second_s == "0") {
        throw BigIntException("Division by zero is prohibited."); ///exception for dividing by zero
    }
    if (first_s == "0") {              /// if first =0 => return 0
        return first;
    }
//    } catch (BigIntException &b) {
//        cout << b.what() << endl;
//    }
    if (first.my_str[0] == '-' && other.my_str[0] == '-') {     /// if first and second are both negative
        first_s = first_s.erase(0, 1);                 /// erase '-' sign
        second_s = second_s.erase(0, 1);
        BigInt f_bigint = BigInt::to_bigint(first_s);
        res = f_bigint.divide(second_s);            /// result = their division
    } else if (first.my_str[0] == '-') {                     ///if first is negative
        first_s = first_s.erase(0, 1);                ///erasing '-' sign
        BigInt f_bigint = BigInt::to_bigint(first_s);
        BigInt temp = f_bigint.divide(second_s);       ///division of first by second
        if (temp != 0) {                                       /// if division!= zero => result = '-' division
            res = '-' + temp.my_str;
        } else {                                         /// if division =0 => return 0
            res = temp;
        }

    } else if (other.my_str[0] == '-') {                   /// if second is negative
        second_s = second_s.erase(0, 1);            /// erase '-' sign
        BigInt f_bigint = BigInt::to_bigint(first_s);
        BigInt temp = f_bigint.divide(second_s);        ///division of first by second
        if (temp != 0) {                                  /// if division!= zero => result = '-' division
            res = '-' + temp.my_str;
        } else {                                             /// if division =0 => return 0
            res = temp;
        }
    } else {                                             /// if they are both positive
        BigInt f = BigInt::to_bigint(first_s);
        res = f.divide(second_s);                      ///division of first by second
    }
    return res;
}
///@endcode
/**
 * @brief Remainder function. It works the same way as division, but returns remainder.
 * @param second
 * @return string
 */
string BigInt::remainder(const string &second) {
    string res;
    string remainder = "0";
    string first = this->my_str;
    try {
        if (second == "0") {
            throw BigIntException("Division by zero is prohibited.");
        }
    } catch (BigIntException &b) {
        cout << b.what() << endl;
    }
    if (first == second) {
        return "0";
    } else {
        if (second == "1") {
            return "0";
        }
        if (to_bigint(second) > to_bigint(first)) {
            return first;
        }
        BigInt temp;
        bool is_left = false;
        bool is_less = false;
        int pos_res = 0;
        BigInt numerator = to_bigint(first);
        string f_copy = first;
        BigInt denum = to_bigint(second);
        string temp_str;
        for (int i = 0; i < first.length(); ++i) {

            if (is_less) {                       /// previous elements was less than divisor and will be inserted to the next element
                temp_str += f_copy[i];          ///adding the previous element
                is_less = false;
            } else {
                temp_str = f_copy[i];
            }
            if (is_left) {                        ///if subtract of the previous element !=0
                temp_str.insert(0, temp.my_str);
                is_left = false;
            }
            if (temp_str >= denum) {                           /// if element >= divisor
                for (int j = 1; j < 10; ++j) {
                    if (j * denum <= temp_str && (j + 1) * denum > temp_str) {
                        res += to_string(j);
                        pos_res++;
                        break;
                    }
                }
                int pos = pos_res - 1;
                string res_str = to_string(res[pos] - '0');
                BigInt b_temp = to_bigint(res_str);
                BigInt mul = b_temp * denum;
                BigInt sub = (temp_str) - mul;
                if (sub > 0) {  /// if subtraction > 0, left result will be added to the next part of dividend
                    temp = sub;
                    is_left = true;
                    if (i + 1 ==
                        first.length()) {   /// if i was the last element, then left part will be stored into remainder
                        remainder = temp.my_str;
                    }
                }

            } else if (temp_str == "0") {       /// if element =0 && the next element !=0
                res += "0";
            } else if (temp_str < denum && i + 1 ==
                                           first.length()) {   /// if element(s) < divisor and it is the last element(s) of dividend
                res += "0";
                remainder = temp_str;               /// store left numbers to remainder
            } else {
                is_less = true;
            }
        }
    }
    return remainder;
}

/**
 * @brief  Operator % overloading. Remainder method was used to overload it.
 *  Erasing '-' sign of negative numbers, and returning positive or negative result
 * according to the signs of each BigInt. Providing exceptions for division by zero.
 * @param other
 * @return BigInt
 * @code
 */
BigInt BigInt::operator%(const BigInt &other) const {
    BigInt first = *this;
    BigInt res;
    string first_s = first.my_str;
    string second_s = other.my_str;
    //try {
    if (second_s == "0") {
        throw BigIntException("Division by zero is prohibited.");  /// exception for dividing by zero
    }
//    } catch (BigIntException b) {
//        cout << b.what() << endl;
//    }
    if (first.my_str[0] == '-' && other.my_str[0] == '-') {    /// if first and second are both negative
        first_s = first_s.erase(0, 1);                  /// erase '-' sign
        second_s = second_s.erase(0, 1);
        BigInt f_bigint = BigInt::to_bigint(first_s);
        BigInt temp = f_bigint.remainder(second_s);     /// calculating remainder of first by second
        if (temp != 0) {                                         /// if remainder !=0 => result ='-' remainder
            res = '-' + temp.my_str;
        } else {                                                  /// else remainder = 0
            res = temp;
        }
    } else if (first.my_str[0] == '-') {                    /// if first is negative
        first_s = first_s.erase(0, 1);               /// erasing '-' sign
        BigInt f_bigint = BigInt::to_bigint(first_s);
        BigInt temp = f_bigint.remainder(second_s);   /// calculating remainder of first by second
        if (temp != 0) {                                        /// if remainder !=0 => result ='-' remainder
            res = '-' + temp.my_str;
        } else {                                                /// else remainder = 0
            res = temp;
        }
    } else if (other.my_str[0] == '-') {                  /// if second is negative
        second_s = second_s.erase(0, 1);          /// erasing '-' sign
        BigInt f_bigint = BigInt::to_bigint(first_s);
        res = f_bigint.remainder(second_s);   /// calculating remainder of first by second
    } else {                                          /// if they are both positive, calculate remainder
        BigInt f = BigInt::to_bigint(first_s);
        res = f.remainder(second_s);
    }
    return res;
}
///@endcode
/**
 * @brief Overloading of % operator.
 * @param first
 * @param second
 * @return BigInt
 */
BigInt operator%(const BigInt &first, const int &second) {
    BigInt temp(second);              /// converting int to BigInt
    return first % temp;                   /// using overloaded % operator for two BigInt
}

/**
 * @brief Overloading of % operator.
 * @param first
 * @param second
 * @return BigInt
 */
BigInt operator%(const int &second, const BigInt &first) {
    BigInt temp(second);                     /// converting int to BigInt
    return temp % first;                             /// using overloaded % operator for two BigInt
}

/**
 * @brief Overloading of % operator.
 * @param first
 * @param second
 * @return BigInt
 */
BigInt operator%(const BigInt &first, long long int second) {
    BigInt temp(second);                      /// converting long long int to BigInt
    return first % temp;                             /// using overloaded % operator for two BigInt
}

/**
 * @brief Overloading of % operator.
 * @param first
 * @param second
 * @return BigInt
 */
BigInt operator%(long long int second, const BigInt &first) {
    BigInt temp(second);                   /// converting long long int to BigInt
    return temp % first;                            /// using overloaded % operator for two BigInt
}

/**
 * @brief Karatsuba multiplication. Fast approach of multiplying big numbers.
 * It is based on dividing big number to parts. Method uses the Karatsuba algorithm recursively to multiply these smaller parts.
 * This involves performing three multiplications instead of the usual four.
 * @param x
 * @param y
 * @return BigInt
 */
BigInt BigInt::karatsuba(const BigInt &x, const BigInt &y) {
    if (x < 10 || y < 10) {
        return x * y;
    }                    // _a_|_b_
        // _c_|_d_
    else {
        /// x = a * 10^(n/2) + b
        /// y = c * 10^(n/2) + d
        /// x * y = ac*10^(2(n/2)) + (ad + bc)* 10^(n/2) + bd
        long long max_len = max(x.my_str.length(), y.my_str.length());
        long long half_of_num = max_len / 2;
        BigInt ten = 10;
        BigInt a = x / (ten.pow((int) half_of_num));  /// a - left side of x num
        BigInt b = x % (ten.pow((int) half_of_num));  /// b - right side of x num
        BigInt c = y / (ten.pow((int) half_of_num));  /// c - left side of y num
        BigInt d = y % (ten.pow((int) half_of_num));  /// d - right side of y num
        BigInt ac = karatsuba(a, c);                     /// recursive call to find a*c
        BigInt bd = karatsuba(b, d);                      /// recursive call to calculate b*d
        BigInt ad_bc = karatsuba(a + b, c + d) - ac -
                       bd;  /// (a+b)(c+d) - ac -bd = ad + bc is what we need according to our formula
        BigInt res = ac * (ten.pow((int) (2 * half_of_num))) + (ad_bc * (ten.pow((int) half_of_num))) +
                     bd; /// according to Karatsuba algorithm
        return res;
    }
}

/**
 * @brief Karatsuba Multiplication for big numbers. It works on Karatsuba method.
 * Erasing '-' sign of negative numbers, and returning positive or negative result
 * according to the signs of each BigInt.
 * @param y
 * @return BigInt
 * @code
 */
BigInt BigInt::karatsubaMultiply(const BigInt &y) {
    BigInt res;
    string first_s = this->my_str;
    string second_s = y.my_str;
    if (first_s == "0" || second_s == "0") {                /// if one of parameters = 0 , return 0
        return 0;
    }
    if (first_s[0] == '-' && y.my_str[0] == '-') {               /// if first and second are both negative
        first_s = first_s.erase(0, 1);                  /// erase '-' sign
        second_s = second_s.erase(0, 1);
        BigInt f_bigint = BigInt::to_bigint(first_s);
        res = karatsuba(f_bigint, to_bigint(second_s));         /// multiply using karatsuba
    } else if (first_s[0] == '-') {                               /// if first if negative
        first_s = first_s.erase(0, 1);                      /// erase '-' sign
        BigInt f_bigint = BigInt::to_bigint(first_s);
        BigInt res1 = karatsuba(f_bigint, to_bigint(second_s));    /// multiply using karatsuba
        res = "-" + res1.my_str;                                            /// result = '-' multiplication
    } else if (y.my_str[0] == '-') {                                  /// if second is negative
        second_s = second_s.erase(0, 1);                     /// erase '-' sign
        BigInt s_bigint = BigInt::to_bigint(second_s);
        BigInt res1 = karatsuba(to_bigint(first_s), s_bigint);           /// multiply using karatsuba
        res = "-" + res1.my_str;                                               /// result = '-' multiplication
    } else {                                                           /// if both are positive => return their karatsuba multiplication
        BigInt f = BigInt::to_bigint(first_s);
        res = karatsuba(f, to_bigint(second_s));
    }
    return res;
}
///@endcode
/**
 * @brief Pow method. It multiplies BigInt, exponent times and updates the BigInt value.
 * @param exponent
 * @return BigInt
 * @code
 */
BigInt BigInt::pow(int exponent) {
    string first = this->my_str;
    BigInt res;
    //try {
    if (first == "0" && exponent == 0) {
        throw BigIntException("Zero to the power of zero is undefined.");  ///exception for undefined value
    }
//    } catch (BigIntException b) {
//        cout << b.what() << endl;
//    }
    if (exponent == 0) {                                              ///h case
        return 1;
    } else if (first[0] == '-' && exponent < 0) {          /// if pow is negative
        if (first == "-1" && exponent == -1) {                    /// (-1)^(-1) = -1
            return -1;
        } else if (first == "-1") {
            if (exponent % 2 == 0) {                             /// (-1)^(even) = 1
                return 1;
            } else {
                return -1;                                         /// (-1)^(odd) = -1
            }
        } else {
            return 0;                                         /// number > 1 in pow < (-1) = 0
        }
    } else if (first[0] == '-') {                           /// if first if negative
        string first_pos = first.erase(0, 1);         /// erasing '-' sign
        BigInt b = to_bigint(first_pos);
        if (exponent % 2 == 0) {                   /// if exponent is even, return positive value
            return b.pow(exponent);
        }
        BigInt r;
        r = b.pow(exponent);
        string s = "-";
        res = s + r.my_str;
        return res;                        /// if exponent is odd, return negative value
    } else if (exponent < 0) {
        if (first == "1") {
            return to_bigint(first);
        } else {
            return 0;
        }
    } else {                             /// if first >0 and exponent >0
        BigInt f = to_bigint(first);
        while (exponent != 1) {
            f = f.multiply(first);  /// multiplying first to itself exponent times
            exponent--;
        }
        return f;
    }
}
///@endcode
/**
 * @brief Factorial method. Multiplies 1 till n. Returns factorial of n.
 * @param n
 * @return BigInt
 * @code
 */
BigInt BigInt::factorial(int n) {
    //try {
    if (n < 0) {
        throw BigIntException(
                "Factorial is defined only for positive numbers and 0."); /// exception for range of numbers
    }
//    } catch (BigIntException b) {
//        cout << b.what() << endl;
//    }
    if (n == 0 || n == 1) {           /// 0!=1!=1
        return 1;
    }
    BigInt res = 1;
    for (int i = 1; i <= n; i++) {  /// for loop for multiplying 1 to n
        res *= i;
    }
    return res;
}
///@endcode
/**
 * @brief GCD (Great Common Divisor) function. It performs euclid method for finding GCD.
 * @param other
 * @return BigInt
 * @code
 */
BigInt BigInt::gcd(const BigInt &other) {
    BigInt res;
    BigInt second = other.my_str;
    BigInt first = *this;
    //try {
    if (first == 0 || second == 0) {
        throw BigIntException(
                "GCD of two zeros OR GCD of zero and another number IS undefined."); ///exception for number's range
    }
//    } catch (BigIntException b) {
//        cout << b.what() << endl;
//    }
    if (first.my_str[0] == '-') {
        first = first.my_str.erase(0, 1);             /// erasing '-' sign
    }
    if (second.my_str[0] == '-') {
        second = second.my_str.erase(0, 1);          /// erasing '-' sign
    }
    if (is_max_and_not_equal(second.my_str, first.my_str)) {
        BigInt temp = second;                            /// if second > first, swapping them
        second.my_str = first.my_str;
        first.my_str = temp.my_str;
    }
    BigInt test;
    while (second != 0) {                               /// while loop for finding GCD
        test = first % second;                        /// storing their remainder
        first = second;                             /// first is equal to second
        second = test;                               /// working until second is equal to zero
    }
    res = first;
    return res;
}
///@endcode
/**
 * @brief Overloading pre increment operator ++.
 * @return BigInt
 * @code
 */
BigInt BigInt::operator++() {
    *this += BigInt(1);    /// the value will +1 before execution
    return *this;
}
///@endcode
/**
 * @brief Overloading post increment operator ++.
 * @return BigInt
 * @code
 */
BigInt BigInt::operator++(int n) {
    BigInt bigInt(this->my_str);  /// the value will +1 after execution
    ++(*this);
    return bigInt;
}
///@endcode
/**
 * @brief Overloading post decrement operator --.
 * @return BigInt
 * @code
 */
BigInt BigInt::operator--(int n) {
    BigInt bigInt(this->my_str);         /// the value will -1 after execution
    --(*this);
    return bigInt;
}
///@endcode
/**
 * @brief Overloading pre decrement operator --.
 * @return BigInt
 * @code
 */
BigInt BigInt::operator--() {
    *this -= BigInt(1);     /// the value will -1 before execution
    return *this;
}
///@endcode
/**
 * @brief Overloading unary + operation.
 * @return Bigint
 * @code
 */
BigInt BigInt::operator+() {
    return *this;                  /// return the same number
}
///@endcode
/**
 * @brief Overloading unary - operation.
 * @return Bigint
 * @code
 */
BigInt BigInt::operator-() {
    string str = this->my_str;
    if (str == "0") {          /// -0 =0
        return str;
    }
    if (str[0] == '-') {   /// -(negative) = positive
        str.erase(0, 1);
        return str;
    }
    return "-" + str;   /// -positive = negative
}
///@endcode

