# 첫 번째 - 1시간 풀고 못 풀었음
N = int(input())
d = [0] * 1001
d[1] = 1
d[2] = 3

for i in range(3, N+1):
  d[i] = (d[i-1] + 2 * d[i-2]) % 796796

print(d[N])

# 두 번째 
# 총 몇 개의 유니크한 방법이 있는지를 구하는 것은 최대 몇 개의 유니크한 방법이 있는 것인지 묻는 것이기 때문에 Optimization 문제
# 내가 이 문제를 못 풀었던 것은 하나의 subproblem의 결과가 다른 subproblem의 결과에 영향을 미칠 수 있다고 생각하기 때문
N = int(input())
d = [0] * 1001

d[0] = 1
d[1] = 3

for i in range(2, N):
  d[i] = d[i-1] + 2 * d[i-2]

print(d[N-1] % 796796)