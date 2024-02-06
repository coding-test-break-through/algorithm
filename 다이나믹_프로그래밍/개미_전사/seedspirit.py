# 60분 정도 걸렸지만... 풀었다..... 만세...
# 점화식은 생각보다 일찍 생각해냈는데 이를 코드로 표현하는 것에서 좀 걸렸음
N = int(input())
inventory = list(map(int, input().split()))

dp = [0] * (N)
dp[0] = inventory[0]
dp[1] = max(inventory[0], inventory[1])

for n in range(2, N):
  dp[n] = max(dp[n-2]+inventory[n], dp[n-1])

print(max(dp))