"""
- 백준 환경에서는 코랩과 달리 디버깅이 진짜 힘들다... 백준 환경에서 디버깅하는 것을 연습해야 할듯
  - 사소한 실수가 진짜 많았다. 주의하자
- `print(end=" ")` 때문에 출력초과가 뜨는 경우가 있었다. 사용할 때 주의 필요
- DFS를 재귀로 푸니까 메모리 초과가 뜬다. 반복문으로 푸는 방법도 익혀야 할듯
  - 반복문으로 푸니까 바로 통과 되었다
- 전역변수 사용 (특히 전역 변수 안에 데이터 값이 변할 때)에 주의하자
"""

# 첫 번째 풀이
from collections import deque

node, edge, v = map(int, input().split())
graph = [[] for _ in range(node + 1)]
for _ in range(edge):
    node1, node2 = map(int, input().split())
    graph[node1].append(node2)
    graph[node2].append(node1)

dfs_result = []
bfs_result = []

def dfs(graph, visited, v, dfs_result):
    visited[v] = True
    dfs_result.append(v)
    for i in graph[v]:
        if visited[i] == False:
            dfs(graph, visited, i, dfs_result)

def bfs(graph, visited, start, bfs_result):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        bfs_result.append(v)
        for i in graph[v]:
            if visited[i] == False:
                queue.append(i)
    return bfs_result


visited = [False] * (node + 1)
dfs(graph, visited, v, dfs_result)

visited = [False] * (node + 1)
bfs(graph, visited, v, bfs_result)

print(" ".join(dfs_result))
print(" ".join(bfs_result))


# 두 번쨰 풀이
"""
- 디버깅 하느라 50분
- 파이썬에서 join 쓸 때는 리스트 원소가 문자열일 때 가능 -> int면 type 에러 남
- bfs에서 vistied의 True 처리를 어느 위치에서 할 지 고민하기: queue에 삽입할 때 다음 방문 예정인 노드들에 대해서 (vs DFS는 현재 노드에 대해서)
"""
node, edge, start = map(int, input().split())
graph = [[] for _ in range(node+1)]
for i in range(edge):
    node1, node2 = map(int, input().split())
    graph[node1].append(node2)
    graph[node2].append(node1)

# 탐색을 위한 정렬
for node_info in graph:
    node_info.sort()
    
 
def dfs(start):
    stack = [start]
    result = []
    visited = [False] * len(graph)
    
    while stack:
        next_node = stack.pop()
        if visited[next_node] == False:
            visited[next_node] = True
            result.append(str(next_node))
            stack.extend(reversed(graph[next_node]))
            
    return result

def bfs(start):
    from collections import deque
    queue = deque([start])
    visited = [False] * len(graph)
    result = []
    
    while queue:
        print(f"queue: {queue}")
        node = queue.popleft()
        visited[node] = True
        result.append(str(node))
        for next_node in graph[node]:   
            if visited[next_node] == False:
                queue.append(next_node)
                
    return result

print(" ".join(dfs(start)))
print(" ".join(bfs(start)))