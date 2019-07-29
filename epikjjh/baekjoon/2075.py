import sys
from heapq import heapify, heappop


def heap_sort(arr):
    heapify(arr)
    ret = []
    while arr:
        ret.append(heappop(arr))
    return ret
    

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
arr = []
for i in range(n):
    arr += list(map(int, input().split()))
    arr = heap_sort(arr)
    if len(arr) > n:
        arr = arr[len(arr)-n:]
print(arr[0])