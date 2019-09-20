import sys

INF = 1000000
input = lambda: sys.stdin.readline().rstrip()
n = int(input())
m = int(input())
cost = [[INF if i!=j else 0 for j in range(n)] for i in range(n)]
for i in range(m):
    a,b,c = map(int,input().split())
    cost[a-1][b-1] = min(cost[a-1][b-1],c)
for k in range(n):
    for i in range(n):
        for j in range(n):
            cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j])
for i in range(n):
    for j in range(n):
        print(cost[i][j] if cost[i][j]!=INF else 0,end=" ")
    print()