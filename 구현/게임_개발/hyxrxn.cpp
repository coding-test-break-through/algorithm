#include <iostream>
using namespace std;

int map[50][50];
int visit[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    int n, m, a, b, d;
    int num = 1;

    // 정보 입력
    cin >> n >> m >> a >> b >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            visit[i][j] = 0;
        }
    }
    visit[a][b] = 1;

    int nx, ny;
    bool move;
    while (true) {
        move = false;
        // 네 방향 중 갈 방향 정하기
        for (int i = 1; i < 4; i++) {
            int direction = (d + i) % 4;
            nx = a + dx[direction];
            ny = b + dy[direction];
            if (map[nx][ny] != 1 && visit[nx][ny] == 0) {
                a = nx;
                b = ny;
                d = direction;
                num++;
                visit[a][b] = 1;
                move = true;
                break;
            }
        }
        // 어느 방향으로도 이동 못했다면 뒤로 갈 수 있는지 확인
        if (!move) {
            nx = a - dx[d];
            ny = b - dy[d];
            if (map[nx][ny] == 1) {
                break;
            }
            else {
                a = nx;
                b = ny;
            }
        }
    }

    cout << num;

    return 0;
}