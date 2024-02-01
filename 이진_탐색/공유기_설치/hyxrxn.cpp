#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int x[200000];
int answer;

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    int low = 1;
    int high = x[n - 1] - x[0];

    while (low <= high) {
        int mid = (low + high) / 2;
        int number = 1;
        int now = x[0];
        for (int i = 0; i < n; i++) {
            if (x[i] >= now + mid) {
                number++;
                now = x[i];
            }
        }

        if (number >= c) {
            cout << mid << " " << number << endl;
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << answer;

    return 0;
}