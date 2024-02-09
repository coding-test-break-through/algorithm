#include <iostream>
#include <vector>
using namespace std;

int n, dummy;
vector<int> power;
int maximum[2000];
int answer = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dummy;
        power.push_back(dummy);
        maximum[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (power[i] < power[j]) {
                maximum[i] = max(maximum[i], maximum[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        answer = max(answer, maximum[i]);
    }

    cout << n - answer;

    return 0;
}