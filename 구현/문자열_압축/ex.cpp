#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 10000;

    for (int i = 1; i <= s.length(); i++) {
        if (s.length() % i == 0) { // 길이의 약수라면 다 해봄
            cout << i << " ";

            map<string, int> count;
            for (int j = 0; j < s.length() / i; j++) {
                string dummy = s.substr(j * i, i);
                cout << dummy << " ";
                if (count.find(dummy) != count.end()) { // 이미 있으면
                    count[dummy]++;
                } else { // 새거 추가
                    count[dummy] = 1;
                }
            }
            cout << count.size() << " ";
            int length = (i + 1) * count.size(); // 자른 문자열의 길이 + 개수 표현을 위한 숫자의 총 개수
            for (const auto& pair : count) {
                if (pair.second == 1)
                    length--;
            }
            cout << length << endl;

            answer = answer > length ? length : answer;
        }
    }

    return answer;
}