# 첫번째 풀이: 바텀업으로 풀었더니 13 * 2 = 26이 되어버림... 아예 다른 방향으로 풀어야할듯
N = int(input())
d = [0] * (N+1)

d[2] = 1
d[3] = 1
d[5] = 1

for n in range(2, N+1):
  if d[n] == 0:
    for k in range(2, n):
      if (k*5 == n) or (k*3 == n) or (k*2 == n) or (k+1 == n):
        d[n] = d[k] + 1
        break

print(d)
print(d[N])

# 두번째 풀이
# 0으로 초기화할지 최대 수로 초기화할지 한 번씩은 고민해봐야 할듯
x = int(input())
d = [0] * 30001

for i in range(2, x+1):
  d[i] = d[i-1] + 1
  if i % 2 == 0:
    d[i] = min(d[i], d[i//2]+1)
  if i % 3 == 0:
    d[i] = min(d[i], d[i//3]+1)
  if i % 5 == 0:
    d[i] = min(d[i], d[i//5]+1)

print(d[x])