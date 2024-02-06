#include <iostream>
#include <algorithm>
using namespace std;

typedef struct student {
    string name;
    int korean;
    int english;
    int math;
}student;

student students[100000];
int n;

bool compare(const student& a, const student& b) {
    if (a.korean != b.korean) {
        return a.korean > b.korean;
    }
    if (a.english != b.english) {
        return a.english < b.english;
    }
    if (a.math != b.math) {
        return a.math > b.math;
    }
    return a.name < b.name;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        int b, c, d;
        cin >> a >> b >> c >> d;
        students[i].name = a;
        students[i].korean = b;
        students[i].english = c;
        students[i].math = d;
    }

    sort(students, students + n, compare);

    for (int i = 0; i < n; i++) {
        cout << students[i].name << endl;
    }

    return 0;
}

// 20분