import heapq

n = int(input())
heap = []
result = 0

for _ in range(n):
    num = int(input())
    heapq.heappush(heap, num)

while len(heap) != 1:
    num1 = heapq.heappop(heap)
    num2 = heapq.heappop(heap)
    
    result += num1 + num2
    heapq.heappush(heap, num1 + num2)

print(result)