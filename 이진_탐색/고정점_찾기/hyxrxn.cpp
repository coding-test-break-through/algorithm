#include <iostream>
using namespace std;

int n;
int arr[1000000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid) {
            cout << mid;
            return 0;
        }
        if (arr[mid] > mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << "-1";
    return 0;
}