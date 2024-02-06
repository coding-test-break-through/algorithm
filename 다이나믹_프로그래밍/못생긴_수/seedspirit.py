# 못 풀었음
# 몇 번째 순서인 못생긴 수를 구해야 한다는 사실 때문에 이전과 같은 dp 테이블 초기화 방식은 안 된다고 생각했음
# an = min(a_n-1 * 2, a_n-1 * 3, a_n-1 * 5) 이런 접근은 알았으나 아래와 같은 방식으로 구현할 수 있을지는 몰랐네요

n = int(input())
ugly = [0] * n
ugly[0] = 1

i2 = i3 = i5 = 0 
next2, next3, next5 = 2, 3, 5

for l in range(1, n):
  ugly[l] = min(next2, next3, next5)
  if ugly[l] == next2:
    i2 += 1
    next2 = ugly[i2] * 2
  if ugly[l] == next3:
    i3 += 1
    next3 = ugly[i3] * 3
  if ugly[l] == next5:
    i5 += 1
    next5 = ugly[i5] * 5

print(ugly[n-1])