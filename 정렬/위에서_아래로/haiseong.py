n = int(input())
lst = [int(input()) for _ in range(n)]
lst.sort(reverse=True)
print(*lst)