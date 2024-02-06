#include <iostream>
#include <queue>
using namespace std;

int n;
int number = 0;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;
        pq.push(card);
    }

    while (pq.size() > 1) {
        int small = pq.top();
        pq.pop();
        int next = pq.top();
        pq.pop();
        int dummy = small + next;
        number += dummy;
        pq.push(dummy);
    }

    cout << number;

    return 0;
}