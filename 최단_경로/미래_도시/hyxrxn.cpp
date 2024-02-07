#include <iostream>
#include <queue>
using namespace std;

int n, m, x, k;
priority_queue<pair<int, int> > pq;
int dist[101]; // 최소 거리 갱신하며 저장
int connect[101][101] = {0}; // 연결 되어있는지 저장... 벡터로 할걸 그랬나?

int d(int start, int end) {
    // 초기화
    for (int i = 0; i <= n; i++) {
        dist[i] = 10000;
    }
    dist[start] = 0;
    pq.push({0, start});

    // 큐 빌 때까지 반복
    while (!pq.empty()) {
        int distance = pq.top().first; // 그 노드까지의 최단거리
        int now = pq.top().second; // 어떤 노드를 거쳐갈지
        pq.pop();
        if (dist[now] < distance) // 이미 방문한 노드
            continue;
        for (int i = 1; i <= n; i++) {
            if (connect[now][i]) { // 연결 되어있는 노드들만 확인
                int cost = distance + 1;
                if (cost < dist[i]) {
                    dist[i] = cost;
                    pq.push({cost, i});
                }
            }
        }

    }
    return dist[end];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        connect[a][b] = 1;
        connect[b][a] = 1;
    }
    cin >> x >> k;

    int answer = d(1, k) + d(k, x);

    if (answer >= 10000) {
        cout << "-1";
    }
    else {
        cout << answer;
    }

    return 0;
}