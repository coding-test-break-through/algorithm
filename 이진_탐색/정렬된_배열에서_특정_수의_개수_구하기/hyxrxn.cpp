#include <iostream>
#include <vector>
using namespace std;

int n, x;
vector<int> v;
int min = 1000000;
int max = -1;

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    auto right = upper_bound(v.begin(), v.end(), x);
    auto left = lower_bound(v.begin(), v.end(), x);

    if (right - left == 0) {
        cout << "-1";
    }
    else {
        cout << right - left;
    }

    return 0;
}