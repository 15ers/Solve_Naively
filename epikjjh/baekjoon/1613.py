import sys

input = sys.stdin.readline
n,k = map(int,input().split())
chart = [[0]*n for i in range(n)]
for _ in range(k):
    a,b = map(int,input().split())
    chart[a-1][b-1] = -1
    chart[b-1][a-1] = 1
for l in range(n):
    for i in range(n):
        for j in range(n):
            if l==i or i==j or l==j:
                continue
            else:
                if not chart[i][j]:
                    if chart[i][l]==1 and chart[l][j]==1:
                        chart[i][j] = 1
                    elif chart[i][l]==-1 and chart[l][j]==-1:
                        chart[i][j] = -1
s = int(input())
for _ in range(s):
    a,b = map(int,input().split())
    print(chart[a-1][b-1])