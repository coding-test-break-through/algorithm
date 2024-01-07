#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main() {
    int n, m, k;
    int sum = 0;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 1; i <= m; i++) {
        if (i % (k + 1) == 0) {
            sum += arr[n - 2];
        } else {
            sum += arr[n - 1];
        }
    }

    cout << sum;

    return 0;
}