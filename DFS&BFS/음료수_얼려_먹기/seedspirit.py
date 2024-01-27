# 처음 풀이 - 못 풀었음
from collections import dequeue

N, M = map(int, input().split())

graph = [list(map(int, list(input()))) for _ in range(N)]
visited = [[False] * M for _ in range(N)]

# 언제 bfs를 쓰고 언제 dfs를 쓰지? 우선 빠르게 True를 기록해나간다고 생각되어지는 bfs 사용
def bfs(coord, visited, graph):
  queue = dequeue()
  visited[coord[0]][coord[1]] = True

  while queue:
    v = queue.popleft()
    if visited[v[0]][v[1]] == False:
      # 범위에 대한 제한을 걸어야 할 것 같은데

answer = 0
for n in range(N):
  for m in range(M):
    if graph[n][m] == 0 and visited[n][m] == 0:
      answer += 1
      bfs(n, m, visited, graph)

print(answer)

# 두 번째 풀었을 때 버전 - 10분 걸림
N, M = map(int, input().split())

graph = [list(map(int, list(input()))) for _ in range(N)]

def dfs(x, y):
  if x <= -1 or x >= n or y <= -1 or y >= m:
    return False
  if graph[x][y] == 0:
    graph[x][y] = 1
    # 상하좌우 모두 재귀적으로 호출
    dfs(x-1, y)
    dfs(x, y-1)
    dfs(x+1, y)
    dfs(x, y+1)
    return True
  return False

answer = 0
for i in range(n):
  for j in range(m):
    if dfs(i, j) == True:
      answer += 1

print(answer)


# 세번째 버전 - 23분 걸림
### 재귀가 아닌 반복문으로 푸는 버전
N, M = map(int, input().split())
graph = [list(map(int, list(input()))) for _ in range(N)]

def dfs(x, y):
  stack = [(x,y)]
  count = 0
  while stack:
    x, y = stack.pop()
    if (x < 0) or (y < 0) or (x >= N) or (y >= M):
      continue
    if graph[x][y] == 0:
      graph[x][y] = 1
      count += 1
      next_move = [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]
      stack.extend(next_move)
  return count

answer = 0
for x in range(N):
  for y in range(M):
    if dfs(x, y) > 0:
      answer += 1

print(answer)