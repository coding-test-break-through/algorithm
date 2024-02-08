#include <iostream>
#include <queue>
using namespace std;

int t, n;
int cost[125][125];
int dist[125 * 125];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void d() {
    for (int i = 0; i < n * n; i++) {
        dist[i] = 100000000;
    }
    dist[0] = cost[0][0];
    pq.push({dist[0], 0});
    while (!pq.empty()) {
        int now = pq.top().second;
        int totalCost = pq.top().first;
        pq.pop();
        if (dist[now] < totalCost)
            continue;
        int x = now / n;
        int y = now % n;
        if (x - 1 >= 0) {
            int nextCost = totalCost + cost[x - 1][y];
            if (nextCost < dist[(x - 1) * n + y]) {
                dist[(x - 1) * n + y] = nextCost;
                pq.push({nextCost, (x - 1) * n + y});
                //cout << x - 1 << ", " << y << "까지 최소값 " << nextCost << "로 갱신" << endl;
            }
        }
        if (x + 1 < n) {
            int nextCost = totalCost + cost[x + 1][y];
            if (nextCost < dist[(x + 1) * n + y]) {
                dist[(x + 1) * n + y] = nextCost;
                pq.push({nextCost, (x + 1) * n + y});
                //cout << x + 1 << ", " << y << "까지 최소값 " << nextCost << "로 갱신" << endl;
            }
        }
        if (y - 1 >= 0) {
            int nextCost = totalCost + cost[x][y - 1];
            if (nextCost < dist[x * n + (y - 1)]) {
                dist[x * n + (y - 1)] = nextCost;
                pq.push({nextCost, x * n + (y - 1)});
                //cout << x << ", " << y - 1 << "까지 최소값 " << nextCost << "로 갱신" << endl;
            }
        }
        if (y + 1 < n) {
            int nextCost = totalCost + cost[x][y + 1];
            if (nextCost < dist[x * n + (y + 1)]) {
                dist[x * n + (y + 1)] = nextCost;
                pq.push({nextCost, x * n + (y + 1)});
                //cout << x << ", " << y + 1 << "까지 최소값 " << nextCost << "로 갱신" << endl;
            }
        }
    }

};

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> cost[j][k];
            }
        }
        d();
        cout << dist[n * n - 1] << endl;
    }

    return 0;
}