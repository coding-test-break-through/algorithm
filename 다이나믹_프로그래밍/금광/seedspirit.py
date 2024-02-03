# 첫번째 풀이 - 접근 방법은 대충 맞는 것 같은데 살짝 디테일이 틀린듯
N, M = map(int, input().split())
mine_tmp = list(map(int, input().split()))
mine = []
for i in range(M, len(mine_tmp), M):
  mine.append(mine_tmp[i-M:i])
dp = [[0]*(M+1) for _ in range(N+1)]


for n in range(1, N+1): # (1,1), (2,1), (3,1) 을 모두 돌아보기
  for m in range(2, M+1):
    dp[n][m] = dp[n][m-1] + mine[n][m]
    if n + 1 <= N + 1:
      dp[n][m] = max(dp[n][m], dp[n][m-1] + mine[n+1][m-1])
    if n - 1 > 0:
      dp[n][m] = max(dp[n][m], dp[n][m-1] + mine[n-1][m-1])

print(max(dp))


## 정답 
for tc in range(int(input())):
  n, m = map(int, input().split())
  array = list(map(int, input().split()))

  dp = []
  index = 0
  for i in range(n):
    dp.append(array[index:index+m])
    index += m


  for j in range(1, m):
    for i in range(n):
      # 왼쪽 위에서 오는 경우
      if i == 0:
        left_up = 0
      else:
        left_up = dp[i-1][j-1]

      # 왼쪽 아래에서 오는 경우
      if i == n-1:
        left_down = 0
      else:
        left_down = dp[i+1][j-1]

      # 왼쪽에서 오는 경우
      left = dp[i][j-1]

      # 최대값 넣기
      dp[i][j] = dp[i][j] + max(left_up, left_down, left)

  result = 0
  for i in range(n):
    result = max(result, dp[i][m-1])

print(result)