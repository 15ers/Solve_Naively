import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
h = []
for i in range(n):
    tmp = int(input())
    if tmp:
        heapq.heappush(h,tmp)
    else:
        if h:
            print(heapq.heappop(h))
        else:
            print(0)