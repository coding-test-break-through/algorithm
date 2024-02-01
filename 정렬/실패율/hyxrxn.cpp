#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<double, int>& a, const pair<double, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int people[501];
double rate[501];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    // 각 스테이지에 있는 인원 수 세기
    for (int i = 0; i < stages.size(); i++) {
        people[stages[i]]++;
    }

    // 각 스테이지별 실패율 계산
    int zero = 0;
    int clear = stages.size();
    for (int i = 1; i <= N; i++) {
        if (clear == 0) {
            rate[i] = 0;
            zero++;
            continue;
        }
        rate[i] = (double)people[i] / clear;
        clear -= people[i];
    }

    // 실패율과 스테이지 번호 페어로 갖는 벡터 생성하고 실패율로 정렬
    vector<pair<double, int>> indexed_values;
    for (int i = 1; i <= N; i++) {
        indexed_values.push_back({rate[i], i});
    }
    sort(indexed_values.begin(), indexed_values.end() - zero, compare);

    // 스테이지 번호만 답 벡터에 push
    for (int i = 0; i < indexed_values.size(); i++) {
        answer.push_back(indexed_values[i].second);
    }

    return answer;
}