//
// Created by User on 06.10.2023.
//
#include "iostream"
#include <stdexcept>

class Kata {
public:
    std::string encrypt(std::string text) {
        std::string range = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,:;-?! '()$%&\"";
        if (text.empty()) {
            return text;
        }
        if (text.find_first_not_of(range) != std::string::npos && text.length() != 88) {
            throw std::invalid_argument("Input contains characters not in the range.");
        }

        std::string res;
        int a, b, result = 0;

        for (int i = 0; i < (int) text.size(); ++i) {
            if (i % 2 != 0 && islower(text[i])) {
                text[i] = (char) (toupper(text[i]));
            } else if (i % 2 != 0 && isupper(text[i])) {
                text[i] = (char) (tolower(text[i]));
            }
        }
        res += range[76 - (range.find(text[0]))];
        for (int i = 1; i < (int) text.size(); ++i) {
            a = (int) range.find(text[i - 1]);
            b = (int) range.find(text[i]);
            result = (int) (((a - b) + range.length()) % range.length());
            if (result > 77) {
                result -= 77;
            }
            res += range[result];
        }

        return res;
    }

    std::string decrypt(std::string encryptedText) {
        if (encryptedText.empty()) {
            return encryptedText;
        }
        std::string range = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,:;-?! '()$%&\"";
        if (encryptedText.find_first_not_of(range) != std::string::npos) {
            throw std::invalid_argument("Input contains characters not in the specified region.");
        }
        std::string res;
        int result;
        encryptedText[0] = range[76 - (range.find(encryptedText[0]))];

        for (int i = 1; i < (int) encryptedText.size(); ++i) {
            result = (int) (range.find(encryptedText[i - 1]) - range.find(encryptedText[i]) + 77) % 77;
            encryptedText[i] = range[result];
        }
        for (int i = 0; i < (int) encryptedText.size(); ++i) {
            if (i % 2 != 0 && isupper(encryptedText[i])) {
                encryptedText[i] = (char) (tolower(encryptedText[i]));
            } else if (i % 2 != 0 && islower(encryptedText[i])) {
                encryptedText[i] = (char) toupper(encryptedText[i]);
            }
        }

        return encryptedText;
    }
};

int main() {
    Kata kata;
    std::string text = "Do the kata \\\"Kobayashi-Maru-Test!\\\" Endless fun and excitement when finding a solution!";
    std::string res = kata.encrypt(text
    );

    std::string res2 = kata.decrypt(
            "$-Wy,dM79H'i'o$n0C&I.ZTcMJw5vPlZc Hn!krhlaa:khV mkL;gvtP-S7Rt1Vp2RV:wV9VuhO Iz3dqb.U0w");
    std::cout << res << "  " << res2 << std::endl;
    return 0;
}