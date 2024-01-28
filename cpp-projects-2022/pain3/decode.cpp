#include <bits/stdc++.h>

std::map<std::string, char> read_codes(const std::string &path) {
    std::ifstream file(path);
    std::string line;
    std::map<std::string, char> codes;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        //format of the line <code>:<symbol>
        std::string code = line.substr(0, line.find(':'));
        std::string symbol_str = line.substr(line.find(':') + 1);
        char symbol;
        if (symbol_str.empty()) {
            symbol = '\n';
        } else {
            symbol = symbol_str[0];
        }

        codes[code] = symbol;
    }

    return codes;
}

std::string decode(std::map<std::string, char> &codes, const std::string &path) {
    std::ifstream out_file(path, std::ios::binary);  // getting bin file by using special mode
    std::string text;
    std::string res;
    char byte;
    while (out_file.get(byte)) {
        std::string temp;
        for (int i = 7; i > -1; --i) {  //checking 8 elements
            if ((byte & (1 << i))) {   //converting byte to binary (string)
                temp += '1'; //if true (1)
            } else {
                temp += '0'; // if false (0)
            }
        }
        text += temp;     // adding to text
        for (const auto &code: codes) {  //iterating through each code
            if (text.substr(0, code.first.length()) == code.first) {   //looking for the same binary code from map codes
                res += code.second;                                           // adding to result the letter of this code
                text.erase(0, code.first.length());                //clearing text
            }
        }
    }
    return res;
}

std::string read_file(const std::string &path) {
    std::ifstream file(path);
    std::string line;
    std::string file_content;
    while (std::getline(file, line)) {
        file_content += line + "\n";
    }
    return file_content;
}


int main() {
    auto codes = read_codes("pain3/encoded_pairs.txt");
    std::string res = decode(codes, "pain3/encoded_text.bin");
    // std::string example = read_file("pain3/ex_text.txt");
    std::ofstream out_file("pain3/decoded_text.txt");
    out_file << res;
}