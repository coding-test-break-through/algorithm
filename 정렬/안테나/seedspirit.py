n = int(input())
houses = list(map(int, input().split()))
least_dist = 100000
answer = 0
for i in range(min(houses), max(houses) + 1): # 집 위치
  dist = 0
  for house in houses:
    dist += abs(i - house)
  if dist < least_dist:
    least_dist = dist
    answer = i

print(answer)