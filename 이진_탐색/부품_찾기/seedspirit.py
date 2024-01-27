N = int(input())
inventory = list(map(int, input().split()))
inventory.sort()
M = int(input())
requests = list(map(int, input().split()))
requests.sort()

def binary_search(array, target, start, end):
  while start <= end:
    mid = (start + end) // 2
    if array[mid] == target:
      return True
    elif array[mid] > target:
      end = mid - 1
    else:
      start = mid + 1
  return None

for request in requests:
  if not binary_search(inventory, request, 0, len(inventory)-1):
    print("no", end=" ")
  else:
    print("yes", end= " ")