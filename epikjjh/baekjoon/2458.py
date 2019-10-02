import sys

INF = 987654321
input = sys.stdin.readline
n,m = map(int,input().split())
graph = [[INF if i!=j else 0 for j in range(n)] for i in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    graph[a-1][b-1] = 1
for k in range(n):
    for i in range(n):
        for j in range(n):
            if graph[i][k]==1 and graph[k][j]==1:
                graph[i][j] = 1
cnt = n
for i in range(n):
    for j in range(n):
        if i!=j and graph[i][j]==INF and graph[j][i]==INF:
            cnt -= 1
            break
print(cnt)