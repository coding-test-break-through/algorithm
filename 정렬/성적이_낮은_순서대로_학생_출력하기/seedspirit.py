n = int(input())
info = []
for _ in range(n):
  name, score = input().split()
  info.append((name, int(score)))
info.sort(key = lambda x: x[1])
for i in info:
  print(i[0], end=" ")