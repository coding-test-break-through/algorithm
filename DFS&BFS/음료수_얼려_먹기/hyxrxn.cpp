#include <iostream>
using namespace std;

int arr[1000][1000];
int visit[1000][1000]; // 방문 했으면 1
int n, m;

void connect(int i, int j) {
    // 상
    if (i - 1 >= 0 && arr[i - 1][j] == 0 && visit[i - 1][j] == 0) {
        visit[i - 1][j] = 1;
        connect(i - 1, j);
    }
    // 하
    if (i + 1 < n && arr[i + 1][j] == 0 && visit[i + 1][j] == 0) {
        visit[i + 1][j] = 1;
        connect(i + 1, j);
    }
    // 좌
    if (j - 1 >= 0 && arr[i][j - 1] == 0 && visit[i][j - 1] == 0) {
        visit[i][j - 1] = 1;
        connect(i, j - 1);
    }
    // 우
    if (j + 1 < m && arr[i][j + 1] == 0 && visit[i][j + 1] == 0) {
        visit[i][j + 1] = 1;
        connect(i, j + 1);
    }
}

int main() {
    int ice = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0 && visit[i][j] == 0) {
                ice++;
                connect(i, j);
            }
        }
    }

    cout << ice;

    return 0;
}