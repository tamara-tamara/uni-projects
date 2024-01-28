//
// Created by User on 12.11.2023.
//
#include <algorithm>
#include "iostream"
#include "vector"
#include "string"
#include "map"

using msv = std::map<std::string, std::vector<char>>;

msv remove_duplicate_ids(const msv &obj) {
    std::vector<int> letters;
    std::vector<int> storage;
    msv temp;
    temp = obj;

    for (auto element : obj) {
        int temp = std::stoi(element.first);
        letters.push_back(temp);
    }

    std::sort(letters.begin(), letters.end(), std::greater<int>()); //sort in DESC

    for (int i = 0; i < (int)letters.size(); ++i) {
        int j = 0;
        while (j < (int)temp[std::to_string(letters[i])].size()) {
            int element = temp[std::to_string(letters[i])][j];
            if (std::find(storage.begin(), storage.end(), element) == storage.end()) {
                storage.push_back(element);
                j++;
            } else {

                temp[std::to_string(letters[i])].erase(temp[std::to_string(letters[i])].begin() + j);
            }
        }
    }
    return temp;
}

int main() {
    msv input = {
            {"1", {'C', 'F', 'G'}},
            {"2", {'A', 'B', 'C'}},
            {"3", {'A', 'B', 'D'}}
    };

    msv output = remove_duplicate_ids(input);

    for (const auto& entry : output) {
        std::cout << entry.first << ": ";
        for (char value : entry.second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}