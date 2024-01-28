#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string number;
        cin >> number;
        int led = 0;

        for (char digit: number) {
            switch (digit) {
                case '0':
                case '9':
                case '6':
                    led += 6;
                    break;
                case '8':
                    led += 7;
                    break;
                case '2':
                case '3':
                case '5':
                    led += 5;
                    break;
                case '4':
                    led += 4;
                    break;
                case '7':
                    led += 3;
                    break;
                case '1':
                    led += 2;
                    break;
            }
        }

        cout << led << " leds" << endl;
    }

    return 0;
}