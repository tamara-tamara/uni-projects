#include <catch2/catch_test_macros.hpp>
#include "BigInt.h"
#include "BigIntException.h"
#include "iostream"
#include <cstdint>

TEST_CASE("Addition is computed", "[Addition]") {
    BigInt s_t(76);
    BigInt s_b(102);
    BigInt s = s_b + s_t;
    REQUIRE(s == BigInt(178));

    BigInt a(1245);
    int b = 254;
    int c = -1254;
    long long d = 1245555555;
    long long e = -1245555;
    REQUIRE(a + b == 1499);
    REQUIRE(c + a == -9);
    REQUIRE(d + a == 1245556800);
    REQUIRE(e + a == -1244310);

    BigInt bigInt_a(0);
    BigInt bigInt_b(" -12");
    bigInt_a = bigInt_a + bigInt_b;  // adding two positive int
    REQUIRE(bigInt_a == -12);

    BigInt neg_a(-32);
    BigInt pos_b(5400);
    neg_a = neg_a + pos_b;   // adding negative and positive int
    REQUIRE(neg_a == 5368);

    BigInt neg_big_a(-99);
    BigInt pos_small_b(99);
    neg_big_a += pos_small_b;
    REQUIRE(neg_big_a == 0);

    BigInt neg_c(-165);
    BigInt neg_d("-2434");
    neg_c = neg_c + neg_d;
    REQUIRE(neg_c == -2599);

    BigInt big_a(922337203685477);
    BigInt big_b(20000012222);
    big_a += big_b;                      // adding long numbers
    REQUIRE(big_a == 922357203697699);
}

TEST_CASE("Subtraction is computed", "[Subtract]") {
    BigInt a(1245);
    int b = 254;
    int c = -1254;
    long long d = 1245555555;
    long long e = -1245555;
    REQUIRE(a - b == 991);
    REQUIRE(c - a == -2499);
    REQUIRE(d - a == 1245554310);
    REQUIRE(e - a == -1246800);

    long long sub_t = 76;
    BigInt sub_b(-89);
    REQUIRE(sub_t - sub_b == 165);

    BigInt bigInt_a_sub(32);
    BigInt bigInt_b_sub(42);
    bigInt_a_sub = bigInt_a_sub - bigInt_b_sub;  // subtracting two positive int
    REQUIRE(bigInt_a_sub == -10);

    BigInt neg_a_s(-32);
    BigInt pos_b_s(5400);
    neg_a_s = neg_a_s - pos_b_s;   // subtracting negative and positive int
    REQUIRE(neg_a_s == -5432);

    BigInt neg_big_a_s(-99);
    BigInt pos_small_b_s(-99);
    neg_big_a_s = neg_big_a_s - pos_small_b_s;
    REQUIRE(neg_big_a_s == 0);

    BigInt neg_c_s(165);
    BigInt neg_d_s("165");
    neg_c_s = neg_c_s - neg_d_s;
    REQUIRE(neg_c_s == 0);

    BigInt big_a_s(922337203685477);
    BigInt big_b_s(20000012222);
    big_a_s -= big_b_s;                      // subtracting long numbers
    REQUIRE(big_a_s == 922317203673255);
}

TEST_CASE("Multiplication is computed", "[Multiplication]") {
    BigInt a(1245);
    int b = 254;
    int c = -1254;
    long long d = 12459;
    long long e = -1245555;
    REQUIRE(a * b == 316230);
    REQUIRE(c * a == -1561230);
    REQUIRE(d * a == 15511455);
    REQUIRE(e * a == -1550715975);

    BigInt bigInt_a_m(-1);
    BigInt bigInt_b_m(0);
    bigInt_a_m = bigInt_a_m * bigInt_b_m;  // adding two positive int
    REQUIRE(bigInt_a_m == 0);

    BigInt neg_a_m(-32);
    BigInt pos_b_m(5400);
    neg_a_m = neg_a_m * pos_b_m;   // adding negative and positive int
    REQUIRE(neg_a_m == -172800);

    BigInt neg_big_a_m(-99);
    BigInt pos_small_b_m(76);
    neg_big_a_m *= pos_small_b_m;
    REQUIRE(neg_big_a_m == -7524);

    BigInt neg_c_m(-165);
    BigInt neg_d_m("-2434");
    neg_c_m = neg_c_m * neg_d_m;
    REQUIRE(neg_c_m == 401610);

    int big_a_m = -92233650;
    BigInt big_b_m(0);
    big_b_m *= big_a_m;                      // adding long numbers
    REQUIRE(big_b_m == 0);
}

TEST_CASE("Division is computed", "[Division]") {
    BigInt a(1245);
    int b = 254;
    int c = -1254;
    long long d = 124555555;
    long long e = -1245555;
    REQUIRE(a / b == 4);
    REQUIRE(c / a == -1);
    REQUIRE(d / a == 100044);
    REQUIRE(e / a == -1000);


    BigInt d1(0);
    BigInt d2(7133);
    BigInt d6(4164392889);
    int d4 = -2;
    long long d5 = 100;
    REQUIRE(d6 / d2 == 583820);
    REQUIRE(d4 / d5 == 0);
    REQUIRE(d1 / d4 == 0);
    REQUIRE_THROWS_AS(d2 / d1, BigIntException);

}

TEST_CASE("Remainder is computed", "[Remainder]") {
    BigInt a(1245);
    int b = 254;
    int c = -1254;
    long long d = 124555555;
    long long e = -1245555;
    REQUIRE(a % b == 229);
    REQUIRE(c % a == -9);
    REQUIRE(-c % -a == 9);
    REQUIRE(d % a == 775);
    REQUIRE(e % a == -555);

    BigInt d1(-20);
    BigInt d2(7133);
    BigInt d6(4164392889);
    int d4 = 2;
    long long d5 = 100;
    REQUIRE(d6 % d2 == 4829);
    REQUIRE(d4 % d5 == d4);
    REQUIRE(d1 % d4 == 0);
    REQUIRE_THROWS(d1 % 0);
}

TEST_CASE("Comparing is computed", "[Comparing]") {
    BigInt a1(0);
    BigInt a11(0);
    BigInt a2(1);
    BigInt a3(-2);
    BigInt a4(-12);
    BigInt a5(100);
    BigInt a6(12950);
    BigInt a7(12);
    BigInt a77(12);
    BigInt a8(-12);
    BigInt a9(24);
    BigInt a10(34);

    REQUIRE(a1 < a2);                                     /// Testing less <
    REQUIRE(a3 < a1);
    REQUIRE(a4 < a3);
    REQUIRE(a5 < a6);

    REQUIRE(a2 > a1);                                       /// Testing more >
    REQUIRE(a10 > a3);
    REQUIRE(a77 > a3);
    REQUIRE(a6 > a4);

    REQUIRE(a6 >= a1);                                   /// Testing more or equal >=
    REQUIRE(a1 >= a11);
    REQUIRE(a8 >= a4);
    REQUIRE(a7 >= a77);

    REQUIRE(a1 <= a11);                                 /// Testing less or equal
    REQUIRE(a8 <= a4);
    REQUIRE(a9 <= a10);
    REQUIRE(a7 <= a77);
    REQUIRE(a1 <= a9);

    REQUIRE(a1 == a11);                                /// Testing equality
    REQUIRE(a77 == a7);
    REQUIRE(a4 == a8);

    REQUIRE(a1 != a4);                              /// Testing non equality
    REQUIRE(a1 != a6);
    REQUIRE(a10 != a9);
    REQUIRE(a2 != a77);
}

TEST_CASE("Factorial is computed", "[Factorial]") {
    int a1 = 0;
    int a2 = 2;
    int a3 = 1;
    int a4 = 12;
    int a5 = -5;
    REQUIRE(BigInt::factorial(a1) == 1);
    REQUIRE(BigInt::factorial(a2) == 2);
    REQUIRE(BigInt::factorial(a3) == 1);
    REQUIRE(BigInt::factorial(a4) == 479001600);
    REQUIRE_THROWS(BigInt::factorial(a5));
}

TEST_CASE("Pow is computed", "[Pow]") {
    BigInt a1(0);
    BigInt a2(1);
    BigInt a3(-2);
    BigInt a4(-12);
    BigInt a5(100);
    BigInt a6(12950);

    REQUIRE_THROWS(a1.pow(0));
    REQUIRE(a2.pow(0) == 1);
    REQUIRE(a3.pow(4) == 16);
    REQUIRE(a3.pow(-4) == 0);
    REQUIRE(a3.pow(-1) == 0);
    REQUIRE(a3.pow(1) == -2);
    REQUIRE(a4.pow(3) == -1728);
    REQUIRE(a4.pow(-3) == 0);
    REQUIRE(a4.pow(-4) == 0);
    REQUIRE(a4.pow(4) == 20736);
    REQUIRE(a5.pow(2) == 10000);
    REQUIRE(a6.pow(0) == 1);
}

TEST_CASE("GCD is computed", "[GCD]") {
    BigInt a1(0);
    BigInt a2(1);
    BigInt a3(-2);
    BigInt a4(-12);
    BigInt a5(100);
    BigInt a6(12950);
    BigInt a7(12);
    BigInt a8(-12);
    BigInt a9(24);
    BigInt a10(34);

    REQUIRE_THROWS(a1.gcd(0));
    REQUIRE_THROWS(a1.gcd(a2));
    REQUIRE_THROWS(a1.gcd(a3));
    REQUIRE(a2.gcd(a3) == 1);
    REQUIRE(a3.gcd(a4) == 2);
    REQUIRE(a5.gcd(a4) == 4);
    REQUIRE(a6.gcd(12950) == 12950);
    REQUIRE(a7.gcd(a8) == 12);
    REQUIRE(a9.gcd(a8) == 12);
    REQUIRE(a10.gcd(a9) == 2);

}

TEST_CASE("Karatsuba is computed", "[Karatsuba]") {
    BigInt bigInt_a_m(-1);
    BigInt bigInt_b_m(0);
    BigInt bigInt_a = bigInt_a_m.karatsubaMultiply(bigInt_b_m);  // adding two positive int
    REQUIRE(bigInt_a == 0);

    BigInt neg_a_m(-32);
    BigInt a("");
    BigInt pos_b_m(5400);
    neg_a_m = neg_a_m.karatsubaMultiply(pos_b_m);  // adding negative and positive int
    REQUIRE(neg_a_m == -172800);

    BigInt neg_big_a_m(-99);
    BigInt pos_small_b_m(76000000);
    neg_big_a_m = neg_big_a_m.karatsubaMultiply(pos_small_b_m);
    REQUIRE(neg_big_a_m == -7524000000);

    BigInt neg_c_m(-16500000);
    BigInt neg_d_m("-243400001");
    neg_c_m = neg_c_m.karatsubaMultiply(neg_d_m);
    REQUIRE(neg_c_m == 4016100016500000);

    int big_a_m = -92233650;
    BigInt big_b_m(0);
    big_b_m = big_b_m.karatsubaMultiply(big_a_m);                      // adding long numbers
    REQUIRE(big_b_m == 0);
}

TEST_CASE("Postfix addition is computed", "[Postfix add]") {
    BigInt a1(0);
    BigInt a2(1);
    BigInt a3(-2);
    BigInt a4(-12);
    BigInt a5(100);
    BigInt a6(12950);
    BigInt a7(12);
    BigInt a8(-12);
    BigInt a9(24);
    BigInt a10(34);

    REQUIRE(a1++ == 0);
    REQUIRE(a2++ == 1);
    REQUIRE(a3++ == -2);
    REQUIRE(a4++ == -12);
    REQUIRE(a5++ == 100);
    REQUIRE(a6++ == 12950);
    REQUIRE(a7++ == 12);
    REQUIRE(a8++ == -12);
    REQUIRE(a9++ == 24);
    REQUIRE(a10++ == 34);

}

TEST_CASE("Prefix addition is computed", "[Prefix add]") {
    BigInt a1(0);
    BigInt a2(1);
    BigInt a3(-2);
    BigInt a4(-12);
    BigInt a5(100);
    BigInt a6(12950);
    BigInt a7(12);
    BigInt a8(-12);
    BigInt a9(24);
    BigInt a10(34);

    REQUIRE(++a1 == 1);
    REQUIRE(++a2 == 2);
    REQUIRE(++a3 == -1);
    REQUIRE(++a4 == -11);
    REQUIRE(++a5 == 101);
    REQUIRE(++a6 == 12951);
    REQUIRE(++a7 == 13);
    REQUIRE(++a8 == -11);
    REQUIRE(++a9 == 25);
    REQUIRE(++a10 == 35);
}

TEST_CASE("Postfix subtraction is computed", "[Postfix sub]") {
    BigInt a1(0);
    BigInt a2(1);
    BigInt a3(-2);
    BigInt a4(-12);
    BigInt a5(100);
    BigInt a6(12950);
    BigInt a7(12);
    BigInt a8(-12);
    BigInt a9(24);
    BigInt a10(34);

    REQUIRE(a1-- == 0);
    REQUIRE(a2-- == 1);
    REQUIRE(a3-- == -2);
    REQUIRE(a4-- == -12);
    REQUIRE(a5-- == 100);
    REQUIRE(a6-- == 12950);
    REQUIRE(a7-- == 12);
    REQUIRE(a8-- == -12);
    REQUIRE(a9-- == 24);
    REQUIRE(a10-- == 34);
}

TEST_CASE("Prefix subtraction is computed", "[Prefix sub]") {
    BigInt a1(0);
    BigInt a2(1);
    BigInt a3(-2);
    BigInt a4(-12);
    BigInt a5(100);
    BigInt a6(12950);
    BigInt a7(12);
    BigInt a8(-12);
    BigInt a9(24);
    BigInt a10(34);

    REQUIRE(--a1 == -1);
    REQUIRE(--a2 == 0);
    REQUIRE(--a3 == -3);
    REQUIRE(--a4 == -13);
    REQUIRE(--a5 == 99);
    REQUIRE(--a6 == 12949);
    REQUIRE(--a7 == 11);
    REQUIRE(--a8 == -13);
    REQUIRE(--a9 == 23);
    REQUIRE(--a10 == 33);
}

TEST_CASE("Unary minus is computed", "[Unary minus]") {
    BigInt a1(0);
    BigInt a2(1);
    BigInt a3(-2);
    BigInt a4(-12);
    BigInt a5(100);
    BigInt a6(12950);
    BigInt a7(12);
    BigInt a8(-12);
    BigInt a9(24);
    BigInt a10(34);

    REQUIRE(-a1 == 0);
    REQUIRE(-a2 == -1);
    REQUIRE(-a3 == 2);
    REQUIRE(-a4 == 12);
    REQUIRE(-a5 == -100);
    REQUIRE(-a6 == -12950);
    REQUIRE(-a7 == -12);
    REQUIRE(-a8 == 12);
    REQUIRE(-a9 == -24);
    REQUIRE(-a10 == -34);
}

TEST_CASE("Unary plus is computed", "[Unary plus]") {
    BigInt a1(0);
    BigInt a2(1);
    BigInt a3(-2);
    BigInt a4(-12);
    BigInt a5(100);
    BigInt a6(12950);
    BigInt a7(12);
    BigInt a8(-12);
    BigInt a9(24);
    BigInt a10(34);

    REQUIRE(+a1 == 0);
    REQUIRE(+a2 == 1);
    REQUIRE(+a3 == -2);
    REQUIRE(+a4 == -12);
    REQUIRE(+a5 == 100);
    REQUIRE(+a6 == 12950);
    REQUIRE(+a7 == 12);
    REQUIRE(+a8 == -12);
    REQUIRE(+a9 == 24);
    REQUIRE(+a10 == 34);
}