# 첫 번째는 못 풀고 두 번째는 풀었다
# 기출 유형인 가장 긴 증가하는 부분 수열 문제도 연습해봐야 할듯
# 두번째로 풀었을 때는 풀었다!

N = int(input())
soldiers = list(map(int, input().split()))
soldiers.reverse()
dp = [1] * (N)

for i in range(1, N):
  for j in range(0, i):
    if soldiers[i] > soldiers[j]:
      dp[i] = max(dp[i], dp[j] + 1)

print(N - max(dp))