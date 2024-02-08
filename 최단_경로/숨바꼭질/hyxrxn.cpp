#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dist[20001];
vector<int> connect[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int where;
int maximum = 0;
int num = 0;

void d() {
    for (int i = 1; i <= n; i++) {
        dist[i] = 100000000;
    }
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int now = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        if (dist[now] < distance)
            continue;
        for (const auto& p : connect[now]) {
            int cost = distance + 1;
            if (cost < dist[p]) {
                dist[p] = cost;
                pq.push({cost, p});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }

    d();

    for (int i = 1; i <= n; i++) {
        maximum = max(maximum, dist[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == maximum) {
            if (num == 0)
                where = i;
            num++;
        }
    }

    cout << where << " " << maximum << " " << num;

    return 0;
}