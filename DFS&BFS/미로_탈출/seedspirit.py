# 첫 번째 풀이 - 못 풀었음
from collections import deque

N, M = map(int, input().split())
graph = [list(map(int, list(input()))) for _ in range(N)]

def bfs(graph):
  queue = deque([(0, 0)])
  graph[0][0] = 0
  answer = 1

  while queue:
    print(queue)
    ps = queue.popleft()
    answer += 1
    if ps[0] == N-1 and ps[y] == M-1: # 맨 마지막 (4, 5)에서 tuple index out of range
      break
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    for i in range(4):
      x = ps[0] + dx[i]
      y = ps[1] + dy[i]
      if x > -1 and x < N and y > -1 and y < M:
        if graph[x][y] == 1:
          graph[x][y] = 0
          queue.append((x,y))

  return answer

print(bfs(graph))


# 두 번째 풀이
from collections import deque
N, M = map(int, input().split())
graph = [list(map(int, list(input()))) for _ in range(N)]

def bfs(x, y, graph, N, M):
  queue = deque()
  dx = [1, -1, 0, 0]
  dy = [0, 0, -1, 1]
  queue.append((x, y))
  while queue:
    x, y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx > -1 and ny > -1 and nx < N and ny < M:
        if graph[nx][ny] == 1:
          graph[nx][ny] = graph[x][y] + 1
          queue.append((nx, ny))

bfs(0, 0, graph, N, M)
print(graph[N-1][M-1])


# 세 번째 풀이 - 20분 걸림
from collections import deque
N, M = map(int, input().split())
graph = [list(map(int, list(input()))) for _ in range(N)]

def bfs(x, y):
  queue = deque()
  queue.append((x,y))
  dx = [1, -1, 0, 0]
  dy = [0, 0, 1, -1]
  while queue:
    x, y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx > -1 and ny > -1 and nx < N and ny < M:
        if graph[nx][ny] == 1:
          graph[nx][ny] = graph[x][y] + 1
          queue.append((nx, ny))


bfs(0, 0)
print(graph[N-1][M-1])