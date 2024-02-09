#include <iostream>
#include <vector>
using namespace std;

int n, t, p;
vector<pair<int, int>> info;
int maximum[16];
int answer = 0;

int main() {
    cin >> n;
    info.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> t >> p;
        info.push_back({t, p});
    }

    for (int i = n; i > 0; i--) {
        if (info[i].first - 1 + i > n) {
            maximum[i] = 0;
        }
        else {
            maximum[i] = info[i].second;
        }
        int sum = 0;
        for (int j = i + info[i].first; j <= n; j++) {
            sum = max(sum, maximum[j]);
        }
        maximum[i] += sum;
    }

    for (int i = 1; i <= n; i++) {
        answer = max(answer, maximum[i]);
    }
    cout << answer;

    return 0;
}