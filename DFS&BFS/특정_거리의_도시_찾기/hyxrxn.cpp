#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;
int a, b;
int arr[300000]; // 거리 저장할 배열
vector<list<int> > way(1000000); // 길 저장할 배열

queue<int> q;

void calculate() {
    q.push(x);
    while(!q.empty()) {
        int present = q.front();
        q.pop();
        for (int i = 0; i < way[present].size(); i++) {

        }
    }
}

int main() {
    cin >> n >> m >> k >> x;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        way[a].push_back(b);
    }




    return 0;
}

//2:50~3:30