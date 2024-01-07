#include <iostream>
using namespace std;

int arr[100][100];

int main() {
    int n, m;
    int num = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
        sort(arr[i], arr[i] + m);
    }

    for (int i = 0; i < n; i++) {
        num = num < arr[i][0] ? arr[i][0] : num;
    }

    cout << num;

    return 0;
}
