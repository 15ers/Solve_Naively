import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
m = int(input())
tar = input()
p = "I"+"OI"*n
k = len(p)

cnt = 0
ind = 0
ret = 0
while ind < m:
    if tar[ind:ind+3] == "IOI":
        cnt += 1
        ind += 2
        if cnt >= n:
            ret += 1
    else:
        ind += 1
        cnt = 0

print(ret)
