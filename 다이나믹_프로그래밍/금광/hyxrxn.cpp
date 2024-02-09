#include <iostream>
using namespace std;

int t, n, m;
int gold[20][20];
int num;
int maximum[20][20];

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> gold[j][k];
            }
        }
        num = 0;
        for (int j = 0; j < n; j++) {
            maximum[j][0] = gold[j][0];
        }
        for (int j = 1; j < m; j++) {
            for (int k = 0; k < n; k++) {
                maximum[k][j] = maximum[k][j - 1] + gold[k][j];
                if (k != 0) {
                    maximum[k][j] = max(maximum[k][j], maximum[k - 1][j - 1] + gold[k][j]);
                }
                if (k != n - 1) {
                    maximum[k][j] = max(maximum[k][j], maximum[k + 1][j - 1] + gold[k][j]);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            num = max(num, maximum[j][m - 1]);
        }
        cout << num << endl;
    }

    return 0;
}