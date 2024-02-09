#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> number;
int cnt = 1;

int main() {
    cin >> n;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    number.push_back(0);
    number.push_back(1);
    int i = 2;
    while (cnt < n) {
        if (i % 2 == 0 && number[i / 2] == 1) {
            number[i] = 1;
            cnt++;
        }
        else if (i % 3 == 0 && number[i / 3] == 1) {
            number[i] = 1;
            cnt++;
        }
        else if (i % 5 == 0 && number[i / 5] == 1) {
            number[i] = 1;
            cnt++;
        }
        else {
            number[i] = 0;
        }
        i++;
    }

    cout << i - 1;

    return 0;
}