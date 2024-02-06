#include <iostream>
#include <algorithm>
using namespace std;

int n;
int position[200000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> position[i];
    }

    sort(position, position + n);

    cout << position[(n - 1) / 2];

    return 0;
}