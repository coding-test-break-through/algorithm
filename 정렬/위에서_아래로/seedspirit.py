n = int(input())
numbers = []
for _ in range(n):
  numbers.append(int(input()))
numbers.sort(reverse = True)
print(" ".join(map(str, numbers)))