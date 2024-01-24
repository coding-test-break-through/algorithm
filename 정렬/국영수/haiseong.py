
n = int(input())
students = []
for _ in range(n):
    name, kor, math, eng = input().split()
    kor = int(kor)
    math = int(math)
    eng = int(eng)
    students.append((name, kor, math, eng))

def compare(s1, s2):
    if s1[1] != s2[1]:
        return -(s1[1] - s2[1])
    if s1[2] != s2[2]:
        return s1[2] - s2[2]
    if s1[3] != s2[3]:
        return -(s1[3] - s2[3])
    if s1[0] < s2[0]:
        return -1
    else:
        return 1

# for i in range(n):
#     for j in range(i + 1, n):
#         if compare(students[i], students[j]) > 0:
#             students[i], students[j] = students[j], students[i]

def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[0]
    tail = arr[1:]

    left = [s for s in tail if compare(s, pivot) <= 0]
    right = [s for s in tail if compare(s, pivot) > 0]

    return quick_sort(left) + [pivot] + quick_sort(right)

students = quick_sort(students)

for s in students:
    print(s[0])