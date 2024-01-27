# 계속해서 문제를 잘못읽어서 못 풀었음;; 다시 맑은 정신에서 푸는 것이 필요

def solution(N, stages):
    total = [0] * len(stages + 1)
    stay = [0] * len(stages + 1)
    fail = [0] * len(stages + 1)
    
    for info in stages:
        for stage in total:
            if stage <= info:
                total[stage] += 1
    
    for info in stages:
        stay[info] += 1
    
    for i in range(len(stages) + 2):
        if total[i] == 0:
            fail[i] = (i, 0)
        else:
            fail[i] = (i, stay[i] / total[i])
        
    fail = fail[1:]
    fail.sort(key= lambda x: -x[1])
    answer = []
    for stage in fail:
        answer.append(stage[0])
    return answer