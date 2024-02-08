#include <ios>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
int u, v, w;
//vector<pair<int, int>> connect[20001];
vector<vector<pair<int, int>>> connect;
//int dist[20001];
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void d(int start) {
    dist.assign(V + 1, 100000000);
    //for (int i = 1; i <= V; i++) {
    //    dist[i] = 100000000;
    //}
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
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E >> K;
    connect.resize(V + 1);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        connect[u].push_back({v, w});
    }

    d(K);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == 100000000)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}