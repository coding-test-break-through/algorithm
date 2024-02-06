#include <iostream>
using namespace std;

int n, m;
int arr[100];
int answer[10001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < 10001; i++) {
        answer[i] = 100000;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        answer[arr[i]] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - arr[j] > 0) {
                answer[i] = min(answer[i], answer[i - arr[j]] + 1);
            }
        }
    }

    if (answer[m] == 100000) {
        cout << "-1";
    }
    else {
        cout << answer[m];
    }

    return 0;
}