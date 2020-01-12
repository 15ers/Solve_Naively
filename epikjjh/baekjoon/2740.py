import sys

input = sys.stdin.readline
a_r,a_c = map(int,input().split())
a = [[] for i in range(a_r)]
for i in range(a_r):
    a[i] = list(map(int,input().split()))
b_r,b_c = map(int,input().split())
b = [[] for i in range(b_r)]
for i in range(b_r):
    b[i] = list(map(int,input().split()))
r = [[0]*b_c for i in range(a_r)]
for i in range(a_r):
    for j in range(a_c):
        for k in range(b_c):
            r[i][k] += a[i][j]*b[j][k]
for i in range(a_r):
    print(*r[i])