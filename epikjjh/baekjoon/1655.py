import sys
import heapq

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
max_heap = []
min_heap = []
for i in range(n):
    elem = int(input())
    if len(min_heap) == len(max_heap):
        heapq.heappush(max_heap,(-elem,elem))
    else:
        heapq.heappush(min_heap,elem)
    if min_heap:
        if min_heap[0] < max_heap[0][1]:
            tmp_min = heapq.heappop(min_heap)
            tmp_max = heapq.heappop(max_heap)[1]
            heapq.heappush(max_heap,(-tmp_min,tmp_min))
            heapq.heappush(min_heap,tmp_max)
    print(max_heap[0][1])