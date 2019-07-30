import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
h = []
for i in range(n):
    e = int(input())
    if e:
        heapq.heappush(h,(-e,e))  
    else:
        if h:
            print(heapq.heappop(h)[1])
        else:
            print(0)