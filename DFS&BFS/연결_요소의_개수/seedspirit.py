# 못 풀었음. 백준에서 40%까지 정답하고 틀림
N, M = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [False] * len(graph)
for _ in range(M):
    node1, node2 = map(int, input().split())
    graph[node1].append(node2)
    graph[node2].append(node1)
    
for node_info in graph:
    node_info.sort()

def dfs(start):
    count = 0
    stack = [start]
    visited[start] = True
    while stack:
        node = stack.pop()
        for next_node in graph[node]:
            if visited[next_node] == False:
                visited[next_node] = True
                count += 1
                stack.extend(graph[next_node])
    return count

connected_components = 0
for node in range(len(graph)):
    dfs_result = dfs(node)
    if dfs_result > 0:
        connected_components += 1
print(connected_components)