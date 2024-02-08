#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, c;
vector<pair<int, int>> massage[30001];
int dist[30001];
int num = 0;
int t = 0;
priority_queue<pair<int, int>> pq;

void d(int start) {
    for (int i = 1; i <= n; i++) {
        dist[i] = 100000000;
    }
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int now = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        if (dist[now] < distance)
            continue;
        for (const auto& p : massage[now]) {
            int cost = distance + p.second;
            if (cost < dist[p.first]) {
                dist[p.first] = cost;
                pq.push({cost, p.first});
            }
        }
    }
}

int main() {
    cin >> n >> m >> c;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        massage[x].push_back({y, z});
    }

    d(c);

    for (int i = 1; i <= n; i++) {
        if (i != c && dist[i] < 100000000) {
            num++;
            t = max(t, dist[i]);
        }
    }

    cout << num << " " << t;

    return 0;
}