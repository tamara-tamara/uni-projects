//
// Created by User on 05.10.2023.
//
#include <string>
#include "iostream"

using namespace std;

std::string format_duration(int seconds) {
    string result;
    if (seconds==0){
        result = "now";
    }
    int time[] = {0, 0, 0, 0, 0};

    string names[] = {"second", "minute", "hour", "day", "year"};
    int counter = 0;
    int temp = 0;
    int div = 0;
    long long nn = 86400 * 365;
    div = seconds / nn;
    if (div > 0) {
        time[4] = div;
        counter++;
        temp = (int)(time[4] * nn);
        seconds -= temp;
    }
    div = seconds / 86400;
    if (div > 0) {
        time[3] = div;
        counter++;
        temp = (time[3] * 86400);
        seconds -= temp;
    }
    div = seconds / 3600;
    if (div > 0) {
        time[2] = div;
        counter++;
        temp = time[2] * 3600;
        seconds -= temp;
    }
    div = seconds / 60;
    if (div > 0) {
        time[1] = div;
        counter++;
        temp = time[1] * 60;
        seconds -= temp;
    }
    if (seconds > 0) {
        time[0] = seconds;
        counter++;
    }
    int space = 0;
    for (int i = 4; i > -1; --i) {
        string tempp;
        if (time[i] == 0) {
            continue;
        }
        tempp = to_string(time[i]);
        result += tempp + " " + names[i];
        if (time[i] > 1) {
            result += 's';
        }
        if ((space + 1) != counter) {
            if ((space+2)==counter) {
                result += " and ";
                space++;
            } else {
                result += ", ";
                space++;
            }
        }
    }
    return result;
}

int main() {
    string n = format_duration(3662);
    cout << n << endl;
    return 0;
}