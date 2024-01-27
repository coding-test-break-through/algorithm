# 못 풀었음
N, C = map(int, input().split())
houses = []
for _ in range(N):
    houses.append(int(input()))
houses.sort()

max_range = (max(houses) - min(houses) + 1) // (C-1)

def binary_search(start, end, target, array):
    mid = (start, end) // 2
    while start <= end:
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            end = mid -1
        else:
            start = mid + 1
    return -1