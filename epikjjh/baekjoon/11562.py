import sys
input = sys.stdin.readline
INF = 987654321
n,m = map(int,input().split())
cost = [[0 if i==j else INF for j in range(n)] for i in range(n)]
for _ in range(m):
    u,v,b = map(int,input().split())
    u -= 1
    v -= 1
    if b:
        cost[u][v] = 0
        cost[v][u] = 0
    else:
        cost[u][v] = 0
        cost[v][u] = 1
for k in range(n):
    for i in range(n):
        for j in range(n):
            cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j])
k = int(input())
for _ in range(k):
    a,b = map(int,input().split())
    print(cost[a-1][b-1])