
#include "BigInt.h"
#include "BigIntException.h"

using namespace std;
/**
 * @brief Custom BigInt Exception. Without argument.
 * @code
 */
const char *BigInt_exception::what() {
    return "BigInt Exception was thrown.";
}

///@endcode
/**
 * @brief Custom BigInt Exception. With argument.
 * @code
 */

BigIntException::BigIntException(const string &msg) {
    this->msg += msg;     /// message of the exception + thrown message
}

const char *BigIntException::what() {
    return (this->msg).c_str();
}
///@endcode

