#include <iostream>
using namespace std;

int n;
int arr[1000];

int main() {
    cin >> n;

    arr[0] = 1;
    arr[1] = 3;

    for (int i = 2; i < n; i++) {
        arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 796796;
    }

    cout << arr[n - 1];

    return 0;
}