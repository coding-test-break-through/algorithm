from collections import Counter

n, x = map(int, input().split())
counter = Counter(list(map(int, input().split())))

if x not in counter:
    print(-1)
else:
    print(counter[x])