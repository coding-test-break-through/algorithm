# 이코테 케이스는 다 통과하는데 백준에서는 틀리다고 나옴
N, M, K, X = map(int, input().split())
graph = [[] for _ in range(N+1)]
distance_map = [0] * len(graph)

for _ in range(M):
  src, dst = map(int, input().split())
  graph[src].append(dst)


# BFS 함수 정의
def bfs(start):
  visited = [False] * len(graph)
  from collections import deque
  queue = deque()
  queue.append(start)
  visited[start] = True
  distance = 0

  while queue:
    node = queue.popleft()
    distance += 1
    for next_node in graph[node]:
      if not visited[next_node]:
        visited[next_node] = True
        distance_map[next_node] = distance
        queue.append(next_node)


# 알고리즘 실행
bfs(X)

# 정답 산출
answer_nodes = []
for index, value in enumerate(distance_map):
  if value == K:
    answer_nodes.append(index)

if len(answer_nodes) == 0:
  print("-1")
else:
  for node in answer_nodes:
    print(node)