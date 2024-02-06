# 첫번째 풀이: 90분 풀었지만 못 풀었음
N, M = map(int, input().split())
d = [0] * 10001
unit = []
for _ in range(N):
  unit.append(int(input()))
unit.sort(reverse = True)

for u in unit:
  d[u] = 1

for n in range(2, M+1):
  candidate = []
  for u in unit:
    if n-u != 0:
      candidate.append(d[n-u] + 1)
  if len(candidate) == 0:
    d[n] = 0
  else:
    d[n] = min(candidate)

    """
    if n-u >= 0:
      if d[n] == 0:
        d[n] = d[n-u] + 1
      else:
        d[n] = min(d[n-u]+1, d[n])
    """

print(d)
if d[n] == 0:
  print(-1)
else:
  print(d[n])

# 최소값을 구하는 문제이면 (min을 써야 하는 문제이면) 아예 dp 테이블을 큰 숫자로 초기화하기
N, M = map(int, input().split())
unit = []
for _ in range(N):
  unit.append(int(input()))

d = [10001] * (M+1)

d[0] = 0
for i in range(N):
  for j in range(unit[i], M+1):
    d[j] = min(d[j], d[j-unit[i]]+1)

if d[M] == 10001:
  print(-1)
else:
  print(d[M])