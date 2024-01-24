import bisect

def count(query, words):
    words = [word for word in words if len(word) == len(query)]

    pivot1 = query.replace('?', 'a')
    pivot2 = query.replace('?', 'z')

    words.sort()

    start = bisect.bisect_left(words, pivot1)
    end = bisect.bisect_right(words, pivot2)
    return end - start


def solution(words, queries):
    reversed_words = [word[::-1] for word in words]
    answer = []
    for query in queries:
        if query[0] == '?':
            reversed_query = query[::-1]
            answer.append(count(reversed_query, reversed_words))
        else:
            answer.append(count(query, words))
    return answer

# 채점 결과
# 정확성: 25.0
# 효율성: 30.0
# 합계: 55.0 / 100.0