student_sort = []  
  
n = int(input())
student_list = [(input().split()) for _ in range(n)]
student_sort = sorted(student_list, key=lambda x:x[1])  
  
for i in range(n):  
    print(student_sort[i][0], end=' ')
# print(" ".join(student_sort[i][0] for i in range(n)))