# 지옥 코테 스터디

## 규칙

- 화요일 17:59분까지 PR
- 기한 내에 PR을 보내지 않을 시 벌금 2만원 (회식 비용으로 사용합니다)
- 회의 때는 문제별 자기 알고리즘 간단하게 소개 + 다음주 문제 선정 + PR Accept
  - 각 챕터의 필수 문제 + 각 챕터별 실전 문제 3개씩을 기본으로 합니다
- 문제는 [이것이 코딩 테스트다](https://github.com/ndb796/python-for-coding-test) 사용
- 15분 정도 고민해보고 답이 안 나온다면 정답 보기
- 정답을 외운다는 생각으로 접근합니다 (고등학교 수학 풀 때 문제 유형 암기하듯)

## 폴더 구조

- `/[알고리즘 분류]/[문제 이름]/[깃허브아이디].py`
  - 알고리즘 분류와 문제 이름은 교재에 있는 것을 기준으로 합니다
- ex) `/그리디/동빈이의 큰 수의 법칙/seedspirit.py`
- 알고리즘 분류와 문제 이름은 전부 다 띄어쓰기 없이 만들기
- 폴더명 이상하면 PR Reject 합니다

## PR 규칙

- [이름] / 문제 유형 이름 | ex) [김보겸] / 그리디
- 커밋 메세지 - [문제 이름] / [걸린 시간] ex) 오리 / 1h 20m
- Labels - 푼 문제의 알고리즘 분류 | ex) 누적합

## 커리큘럼
<img width="585" alt="스크린샷 2024-01-03 오후 11 10 01" src="https://github.com/coding-test-break-through/algorithm/assets/109015852/af097f91-bff5-494b-9a99-af59b854b6f2">


### 1주차: 그리디 & 구현
#### 그리디

- 실전
    - 동빈이의 큰 수의 법칙: ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/3/2.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/3/2.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/3/2.java))
    - 숫자 카드게임: ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/3/4.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/3/4.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/3/4.java))
    - 1이 될 때까지: ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/3/6.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/3/6.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/3/6.java))
- 기출문제
    - 모험가 길드 (핵심 유형): ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/11/1.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/11/1.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/11/1.java))
    - 곱하기 혹은 더하기 (Facebook 인터뷰 기출): ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/11/2.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/11/2.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/11/2.java))
    - [문자열 뒤집기](https://www.acmicpc.net/problem/1439) (핵심 유형): ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/11/3.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/11/3.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/11/3.java))

#### 구현

- 실전
    - 왕실의 나이트: ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/4/3.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/4/3.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/4/3.java))
    - 게임 개발: ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/4/4.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/4/4.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/4/4.java))
- 기출문제
    - [럭키 스트레이트](https://www.acmicpc.net/problem/18406) (핵심 유형): ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/12/1.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/12/1.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/12/1.java))
    - 문자열 재정렬 (Facebook 인터뷰 기출): ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/12/2.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/12/2.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/12/2.java))
    - [문자열 압축](https://programmers.co.kr/learn/courses/30/lessons/60057) (카카오): ([Python 3.7 코드](https://github.com/ndb796/python-for-coding-test/blob/master/12/3.py) / [C++ 코드](https://github.com/ndb796/python-for-coding-test/blob/master/12/3.cpp) / [Java 코드](https://github.com/ndb796/python-for-coding-test/blob/master/12/3.java))
