import sys

INF = 987654321
input = sys.stdin.readline
n,m = map(int,input().split())
bacon = [[0 if i==j else INF for j in range(n)] for i in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    bacon[a-1][b-1] = bacon[b-1][a-1] = 1
for k in range(n):
    for i in range(n):
        for j in range(n):
            bacon[i][j] = min(bacon[i][j],bacon[i][k]+bacon[k][j])
sums = list(map(sum,bacon))
print(sums.index(min(sums))+1)