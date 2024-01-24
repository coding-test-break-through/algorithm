# 최선 O(logN) 최악 O(N)
N, x = map(int, input().split())
array = list(map(int, input().split()))
result = 0

def binary_search(start, end, target, array):
  while start <= end:
    mid = (start + end) // 2
    if array[mid] > target:
      end = mid - 1
    elif array[mid] < target:
      start = mid + 1
    else:
      global result
      result += 1
      binary_search(start, mid-1, target, array)
      binary_search(mid+1, end, target, array)

binary_search(0, N-1, x, array)

if result == 0:
  print("-1")
else:
  print(result)