# 30분 풀었음 (시간복잡도: 최선 O(1) 최악 O(log(N)))
# 근데 다시 생각해보니 그냥 평범한 이진탐색으로 풀었어도 될듯

N = int(input())
numbers = list(map(int, input().split()))

def binary_search(start, end, array):
  mid = (start + end) // 2
  while start <= end:
    if array[mid] == mid:
      return mid
    elif array[mid] < 0:
      start = mid + 1
      mid = (start + end) // 2
    elif array[mid] > mid:
      end = mid - 1
      mid = (start + end) // 2
    else:
      mid += 1
  return -1

result = binary_search(0, len(numbers)-1, numbers)
if result == -1:
  print("-1")
else:
  print(result)