# 못 풀었음
N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
blank_coord = []
for i in range(N):
  for j in range(M):
    if graph[i][j] == 0:
      blank_coord.append((i,j))


def simulation(shields):
  simulation_graph = graph
  for shield in shields:
    x, y = shield
    simulation_graph[x][y] = 1

  from collections import deque
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
        if simulation_graph[nx][ny] == 0:
          simulation_graph[nx][ny] = 2
          queue.append((nx, ny))
  
  count = 0
  for i in range(N):
    for j in range(M):
      if simulation_graph[i][j] == 0:
        count += 1
  
  return count

answer = []
for i in range(len(blank_coord)-2):
  for j in range(i+1, len(blank_coord)-1):
    for k in range(j+1, len(blank_coord)):
      shields = [blank_coord[i], blank_coord[j], blank_coord[k]]
      answer.append(simulation(shields))

print(max(answer))