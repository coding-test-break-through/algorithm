# 한 시간 풀었지만 풀지 못했다
def balanced(p):
    left = 0
    right = 0
    for s in p:
        if s == "(":
            left += 1
        elif s == ")":
            right += 1
    return left == right

def alright(p):
    index = len(p) // 2
    return (")" not in p[:index]) and ("(" not in p[index:])

def switch(p):
    result = ''
    for s in p:
        if s == '(':
            result += ')'
        elif s == ')':
            result += '('
    return result


def solution(p):
    answer = ''
    for index in range(2, len(p) // 2 + 1):
        u = p[:index]
        v = p[index:]
        if balanced(u):
            break
    if alright(u):
        answer = solution(v) + u
    else:
        answer += '(' + v + ')' + switch(u[1:len(u)])
    return answer

solution(input())