# 1차 시도 - 20분에 풀긴했는데 시간초과 판정뜰듯
N, M = map(int, input().split())
ddeok_set = list(map(int, input().split()))
ddeok_set.sort()

cut_result = []
for cutter in range(ddeok_set[-1]):
  copy_ddeok_set = ddeok_set[:]
  result = sum(map(lambda ddeok: ddeok - cutter if ddeok-cutter > 0 else 0, copy_ddeok_set))
  if result >= M:
    cut_result.append((cutter, result))
cut_result.sort(key=lambda x: -x[0])
answer = cut_result[0][0]
print(answer)


# 2차 시도 - 20분
N, M = map(int, input().split())
ddeok_set = list(map(int, input().split()))
ddeok_set.sort()
start = 0
end = max(ddeok_set)

# 이진 탐색 방법으로 절단기 길이 찾기
answer = 0
while start <= end:
  mid = (start + end) // 2
  cut_result = sum(map(lambda x: x - mid if x - mid > 0 else 0, ddeok_set[:]))
  print(f"mid:{mid} / cut_result:{cut_result}")
  if cut_result < M:
    end = mid - 1
  elif cut_result == M:
    answer = mid
    break
  else:
    answer = mid
    start = mid + 1

print(answer)