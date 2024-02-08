#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, start, stop;
vector<int> dist;
vector<vector<pair<int, int>>> connect;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int d() {
    dist.assign(n + 1, 100000000);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int now = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        if (dist[now] < distance)
            continue;
        for (const auto& p : connect[now]) {
            int cost = distance + p.second;
            if (dist[p.first] > cost) {
                dist[p.first] = cost;
                pq.push({cost, p.first});
            }
        }
    }
    return dist[stop];
}

int main() {
    cin >> n >> m;
    connect.resize(n + 1);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        connect[a].push_back({b, c});
    }
    cin >> start >> stop;

    cout << d();

    return 0;
}