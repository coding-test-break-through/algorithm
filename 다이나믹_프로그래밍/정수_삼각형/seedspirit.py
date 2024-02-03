# 첫 번째 풀이: 접근은 맞는데 원가 살짝 틀렸다
N = int(input())
triangle = []
for _ in range(N):
  triangle.append(list(map(int, input().split())))
dp = triangle[:]

for n in range(1, N):
  for m in range(len(triangle[n])-1):
    left_down = dp[n-1][m] + triangle[n][m]
    right_down = 0
    if m + 1 < len(triangle[n-1]):
      right_down = dp[n-1][m] + triangle[n-1][m+1]
    dp[n][m] = max(left_down, right_down)


print(dp)

# GPT의 도움을 받은 정답
# 점화식을 세울 때 현재의 행위가 미래에 어떤 결과를 만들 것인가가 아니라 / 현재가 과거의 어떤 행위로 구성되는가에 대해서 조금 더 포커싱해야 할듯

N = int(input())
triangle = []
for _ in range(N):
  triangle.append(list(map(int, input().split())))
dp = triangle[:]

for n in range(1, N):
  for m in range(len(triangle[n])):
    # 왼쪽 위에서 오는 경우
    if m > 0:
      left_down = dp[n-1][m-1] + triangle[n][m]
    else:
      left_down = 0

    # 오른쪽 위에서 오는 경우
    if m < len(triangle[n-1]):
      right_down = dp[n-1][m] + triangle[n][m]
    else:
      right_down = 0

    dp[n][m] = max(left_down, right_down)
print(max(dp[N-1]))