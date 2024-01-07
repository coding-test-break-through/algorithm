#include <iostream>
using namespace std;

int main() {
    int n, k;
    int num = 0;

    cin >> n >> k;

    while (n != 1) {
        if (n % k == 0) {
            n /= k;
        } else {
            n -= 1;
        }
        num++;
    }

    cout << num;

    return 0;
}