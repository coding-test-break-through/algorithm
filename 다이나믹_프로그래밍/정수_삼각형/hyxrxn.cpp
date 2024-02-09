#include <iostream>
#include <vector>
using namespace std;

int n, dummy;
vector<vector<int>> num;
vector<vector<int>> maximum;
int answer = 0;

int main() {
    cin >> n;
    num.resize(n);
    maximum.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> dummy;
            num[i].push_back(dummy);
        }
    }
    maximum[0].push_back(num[0][0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                maximum[i].push_back(maximum[i - 1][j] + num[i][j]);
            }
            else if (j == i) {
                maximum[i].push_back(maximum[i - 1][j - 1] + num[i][j]);
            }
            else {
                maximum[i].push_back(max(maximum[i - 1][j - 1], maximum[i - 1][j]) + num[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        answer = max(answer, maximum[n - 1][i]);
    }
    cout << answer;

    return 0;
}