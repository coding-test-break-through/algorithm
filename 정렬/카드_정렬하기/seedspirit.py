# 자료 구조를 써서 풀어야함;; 해성님의 설명이 필요...
n = int(input())
decks = []
for _ in range(n):
    decks.append(int(input()))
decks.sort()
answer = 0

for i in range(len(decks)):
    answer += (n-i) * decks[i]
answer -= decks[0]
print(answer)