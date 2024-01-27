"""
- 30분 정도 풀었음
- 코랩에서 이코테 케이스는 다 통과하나 백준에서는 시간 초과
  - 아마 for문이 너무 많아서 그런듯
"""

from collections import deque

N, K = map(int, input().split())
graph = []
for _ in range(N):
    graph.append(list(map(int, input().split())))
S, X, Y = map(int, input().split())

def infection(virus_number):
    queue = deque()
    for x in range(N):
        for y in range(N):
            if graph[x][y] == virus_number:
                queue.append((x,y))
    while queue:
        x, y = queue.popleft()
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx > -1 and ny > -1 and nx < N and ny < N:
                if graph[nx][ny] == 0:
                    graph[nx][ny] = virus_number
            

for _ in range(S):
    for virus in range(1, K+1):
        infection(virus)

if graph[X-1][Y-1] == 0:
    print("0")
else:
    print(graph[X-1][Y-1])