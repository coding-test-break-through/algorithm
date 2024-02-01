#include <iostream>
using namespace std;

int n;
int k[1000];
int answer[1000];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }

    answer[0] = k[0];
    answer[1] = k[1];
    answer[2] = k[2] + answer[0];

    for (int i = 3; i < n; i++) {
        answer[i] = max(answer[i - 2], answer[i - 3]) + k[i];
    }

    cout << max(answer[n - 1], answer[n - 2]);

    return 0;
}