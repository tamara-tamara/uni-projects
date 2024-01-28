
#ifndef PERSONAL_GIT_REPO_ALIMKANOVA_T_AUCA_2022_BIGINT_H
#define PERSONAL_GIT_REPO_ALIMKANOVA_T_AUCA_2022_BIGINT_H

#include "string"
#include "iostream"

using namespace std;

/**
 * @Header file of BigInt
 */
class BigInt {
private:
    /// Core functions
    string my_str;

    string add(const string &second);

    string subtract(const string &second);

    string multiply(string second);

    /// compare functions

    static string bigint_max(string first, string second);

    static string bigint_min(string first, string second);

    static bool is_max(const string &first, string second);

    static bool is_min(const string &first, string second);

    static bool is_max_and_not_equal(string first, string second);

    static bool is_min_and_not_equal(const string &first, const string &second);

    /// helper functions

    static BigInt to_bigint(string s);

    static string delete_zeros(string &input_string);

    static string delete_leading_and_last_spaces(string &input_string);

    static bool is_bigint(string str);

    /// advanced functions
    string divide(const string &second);

    string remainder(const string &second);

    BigInt karatsuba(const BigInt &x, const BigInt &y);


public:

/// Constructors

    BigInt(int num);

    BigInt(string s);

    BigInt();

    BigInt(long long l_num);

    BigInt(const BigInt &num);

    /// advanced functions

    BigInt pow(int exponent);

    static BigInt factorial(int n);

    BigInt gcd(const BigInt &other);

    BigInt karatsubaMultiply(const BigInt &y);

    /// Operators overloading

    friend ostream &operator<<(ostream &os, const BigInt &n);

    friend istream &operator>>(istream &os, BigInt &n);

    friend BigInt operator+(const BigInt &other);

    friend BigInt operator+(const BigInt &first, const BigInt &second);

    friend BigInt operator+(const BigInt &first, int second);

    friend BigInt operator+(int second, const BigInt &first);

    friend BigInt operator+(const BigInt &first, long long second);

    BigInt &operator+=(const BigInt &other) {
        (*this) = (*this) + other;
        return (*this);
    }

    friend BigInt operator-(const BigInt &other);

    friend BigInt operator-(const BigInt &first, const BigInt &second);

    friend BigInt operator-(const BigInt &first, int second);

    friend BigInt operator-(const int &second, const BigInt &first);

    friend BigInt operator-(const BigInt &first, long long second);

    BigInt &operator-=(const BigInt &other) {
        (*this) = (*this) - other;
        return (*this);
    }

    BigInt operator*(const BigInt &other) const;

    BigInt &operator*=(const BigInt &other) {
        (*this) = (*this) * other;
        return (*this);
    }

    friend BigInt operator*(const BigInt &first, const int &second);

    friend BigInt operator*(const int &second, const BigInt &first);

    friend BigInt operator*(const BigInt &first, long long second);

    friend BigInt operator*(long long second, const BigInt &first);

    BigInt operator/(const BigInt &other) const;

    BigInt &operator/=(const BigInt &other) {
        (*this) = (*this) / other;
        return (*this);
    }

    friend BigInt operator/(const BigInt &first, const int &second);

    friend BigInt operator/(const int &second, const BigInt &first);

    friend BigInt operator/(const BigInt &first, long long second);

    friend BigInt operator/(long long second, const BigInt &first);

    BigInt operator%(const BigInt &other) const;

    BigInt &operator%=(const BigInt &other) {
        (*this) = (*this) % other;
        return (*this);
    }

    friend BigInt operator%(const BigInt &first, const int &second);

    friend BigInt operator%(const int &second, const BigInt &first);

    friend BigInt operator%(const BigInt &first, long long second);

    friend BigInt operator%(long long second, const BigInt &first);

    bool operator>(const BigInt &other) {
        return is_max_and_not_equal(my_str, other.my_str);
    }

    bool operator>(int num) {
        return is_max_and_not_equal(my_str, to_string(num));
    }

    bool operator>(long long num) {
        return is_max_and_not_equal(my_str, to_string(num));
    }

    friend bool operator>(const BigInt &first, const BigInt &second) {
        return is_max_and_not_equal(first.my_str, second.my_str);
    }

    friend bool operator>(const BigInt &first, int num) {
        return is_max_and_not_equal(first.my_str, to_string(num));
    }

    friend bool operator>(const BigInt &first, long long num) {
        return is_max_and_not_equal(first.my_str, to_string(num));
    }

    friend bool operator>(int num, const BigInt &first) {
        return is_max_and_not_equal(to_string(num), first.my_str);
    }

    friend bool operator>(long long num, const BigInt &first) {
        return is_max_and_not_equal(to_string(num), first.my_str);
    }


    bool operator<(const BigInt &other) {
        return is_min_and_not_equal(my_str, other.my_str);
    }

    bool operator<(int num) {
        return is_min_and_not_equal(my_str, to_string(num));
    }

    bool operator<(long long num) {
        return is_min_and_not_equal(my_str, to_string(num));
    }

    friend bool operator<(const BigInt &first, const BigInt &second) {
        return is_min_and_not_equal(first.my_str, second.my_str);
    }

    friend bool operator<(const BigInt &first, int num) {
        return is_min_and_not_equal(first.my_str, to_string(num));
    }

    friend bool operator<(const BigInt &first, long long num) {
        return is_min_and_not_equal(first.my_str, to_string(num));
    }

    friend bool operator<(int num, const BigInt &first) {
        return is_min_and_not_equal(to_string(num), first.my_str);
    }

    friend bool operator<(long long num, const BigInt &first) {
        return is_min_and_not_equal(to_string(num), first.my_str);
    }

    bool operator>=(const BigInt &first) {
        return is_max(my_str, first.my_str);
    }

    bool operator>=(int num) {
        return is_max(my_str, to_string(num));
    }

    bool operator>=(long long num) {
        return is_max(my_str, to_string(num));
    }

    friend bool operator>=(const BigInt &first, const BigInt &second) {
        return is_max(first.my_str, second.my_str);
    }

    friend bool operator>=(const BigInt &first, int num) {
        return is_max(first.my_str, to_string(num));
    }

    friend bool operator>=(const BigInt &first, long long num) {
        return is_max(first.my_str, to_string(num));
    }

    friend bool operator>=(int num, const BigInt &first) {
        return is_max(to_string(num), first.my_str);
    }

    friend bool operator>=(long long num, const BigInt &first) {
        return is_max(to_string(num), first.my_str);
    }


    bool operator<=(const BigInt &first) {
        return is_min(my_str, first.my_str);
    }

    bool operator<=(int num) {
        return is_min(my_str, to_string(num));
    }

    bool operator<=(long long num) {
        return is_min(my_str, to_string(num));
    }

    friend bool operator<=(const BigInt &first, const BigInt &second) {
        return is_min(first.my_str, second.my_str);
    }

    friend bool operator<=(const BigInt &first, int num) {
        return is_min(first.my_str, to_string(num));
    }

    friend bool operator<=(const BigInt &first, long long num) {
        return is_min(first.my_str, to_string(num));
    }

    friend bool operator<=(int num, const BigInt &first) {
        return is_min(to_string(num), first.my_str);
    }

    friend bool operator<=(long long num, const BigInt &first) {
        return is_min(to_string(num), first.my_str);
    }


    bool operator==(const BigInt &first) {
        return (*this).my_str == first.my_str;
    }

    bool operator==(int num) {
        return (*this).my_str == to_string(num);
    }

    bool operator==(long long num) {
        return (*this).my_str == to_string(num);
    }

    friend bool operator==(const BigInt &first, const BigInt &second) {
        return second.my_str == first.my_str;
    }

    friend bool operator==(const BigInt &first, int num) {
        return to_string(num) == first.my_str;
    }

    friend bool operator==(const BigInt &first, long long num) {
        return to_string(num) == first.my_str;
    }

    friend bool operator==(int num, const BigInt &first) {
        return to_string(num) == first.my_str;
    }

    friend bool operator==(long long num, const BigInt &first) {
        return to_string(num) == first.my_str;
    }

    bool operator!=(const BigInt &first) {
        return (*this).my_str != first.my_str;
    }

    bool operator!=(int num) {
        return (*this).my_str != to_string(num);
    }

    bool operator!=(long long num) {
        return (*this).my_str != to_string(num);
    }

    friend bool operator!=(const BigInt &first, const BigInt &second) {
        return second.my_str != first.my_str;
    }

    friend bool operator!=(const BigInt &first, int num) {
        return to_string(num) != first.my_str;
    }

    friend bool operator!=(const BigInt &first, long long num) {
        return to_string(num) != first.my_str;
    }

    BigInt operator++();

    BigInt operator++(int n);

    BigInt operator--(int n);

    BigInt operator--();

    BigInt operator+();

    BigInt operator-();

};


#endif //PERSONAL_GIT_REPO_ALIMKANOVA_T_AUCA_2022_BIGINT_H
