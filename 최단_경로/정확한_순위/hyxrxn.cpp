#include <iostream>
#include <set>
using namespace std;

int n, m;
set<int> smaller[501];
set<int> larger[501];
int num = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        smaller[b].insert(a);
        larger[a].insert(b);
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            for (const auto &p: smaller[i]) { // i보다 작은 p
                for (const auto &q: smaller[p]) { // p보다 작은 q
                    smaller[i].insert(q);
                    larger[q].insert(i);
                }
            }
        }
    }

    for (int i = 1; i <=n; i++) {
        if (smaller[i].size() + larger[i].size() == n - 1) {
            num++;
        }
    }

    cout << num;

    return 0;
}