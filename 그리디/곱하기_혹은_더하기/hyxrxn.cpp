#include <iostream>
using namespace std;

int main() {
    string s;

    cin >> s;

    int num = s[0] - '0';
    for (int i = 1; i < s.length(); i++) {
        int dummy = s[i] - '0';
        if (dummy <= 1 || num == 0) {
            num += dummy;
        } else{
            num *= dummy;
        }
    }

    cout << num;

    return 0;
}