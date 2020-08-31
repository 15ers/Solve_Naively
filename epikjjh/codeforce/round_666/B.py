import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
arr = list(map(int,input().split()))
arr.sort()
total = sum(arr)
ret = total-n

c = 2
while c**(n-1)<=2*total:
    tmp = [-1*(c**i) for i in range(n)]
    cand = 0
    for i in range(n):
        cand += abs(tmp[i]+arr[i])
    ret = min(ret,cand)
    c += 1

print(ret)
