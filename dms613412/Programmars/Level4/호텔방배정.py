import sys
sys.setrecursionlimit(100000) #파이썬3에는 기본 재귀 제한이 있고 이게 약 1000회

m = {}
def find(x):
    if not x in m.keys():
        return x
    m[x]=find(m[x])
    return m[x]

def solution(k, room_number):
    answer = []

    for x in room_number:
        if x in m.keys():
            tmp = find(m[x])
            answer.append(tmp)
            m[tmp]=find(tmp+1)            
        else:
            answer.append(x)
            m[x]=find(x+1)    
    
    return answer
