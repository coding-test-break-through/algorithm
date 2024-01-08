#include <iostream>
using namespace std;

int main() {
    string s;
    int num = 0;

    cin >> s;

    char dummy = s[0] - '0';
    for (int i = 1; i < s.length(); i++) {
        if (s[i] - '0' != dummy) {
            num++;
            dummy = s[i] - '0';
        }
    }

    if (num % 2 == 0) {
        num /= 2;
    } else {
        num /= 2;
        num++;
    }

    cout << num;

    return 0;
}