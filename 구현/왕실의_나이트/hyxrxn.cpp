#include <iostream>
using namespace std;

int main() {
    int row, col;
    string input;
    int num = 0;

    cin >> input;
    row = input[0] - 'a' + 1;
    col = input[1] - '0';

    if (row - 2 >= 1) {
        if (col - 1 >= 1) num++;
        if (col + 1 <= 8) num++;
    }

    if (row + 2 <= 8) {
        if (col - 1 >= 1) num++;
        if (col + 1 <= 8) num++;
    }

    if (col - 2 >= 1) {
        if (row - 1 >= 1) num++;
        if (row + 1 <= 8) num++;
    }

    if (col + 2 <= 8) {
        if (row - 1 >= 1) num++;
        if (row + 1 <= 8) num++;
    }

    cout << num;

    return 0;
}