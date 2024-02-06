#include <iostream>
#include <queue>
using namespace std;

int n, m;

int arr[200][200];
// 상, 하, 좌, 우 순서
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

typedef struct dot{
    int x;
    int y;
} dot;

queue<dot> dots;

void bfs(int x, int y) {
    dot present;
    present.x = x;
    present.y = y;
    dots.push(present);
    while (!dots.empty()) {
        dot next = dots.front();
        dots.pop();
        for (int i = 0; i < 4; i++) {
            int nx = next.x + dx[i];
            int ny = next.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (arr[nx][ny] == 0)
                continue;
            if (arr[nx][ny] == 1) {
                dot element;
                element.x = nx;
                element.y = ny;
                arr[nx][ny] = arr[next.x][next.y] + 1;
                dots.push(element);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0'; // 괴물이 있으면 0
        }
    }

    bfs(0,0);

    cout << arr[n - 1][m - 1];

    return 0;
}

// 책에 파이썬 답지 보고 품... ㅠㅠ