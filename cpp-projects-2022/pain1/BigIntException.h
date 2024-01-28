
#ifndef PAIN1_BIGINT_EXCEPTION_H
#define PAIN1_BIGINT_EXCEPTION_H

#endif //PAIN1_BIGINT_EXCEPTION_H

#include "exception"

class BigIntException : public std::exception {  /// Exception with argument
private:
    string msg = "BigInt_Exception: ";
public:
    explicit BigIntException(const string &msg = " ");

    const char *what();
};

class BigInt_exception : public std::exception {    /// Exception without argument
public:
    const char *what();
};