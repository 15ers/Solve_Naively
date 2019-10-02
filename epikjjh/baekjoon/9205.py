import sys

INF = 987654321
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    dist = [list(map(int,input().split())) for i in range(n+2)]
    graph = [[0]*(n+2) for i in range(n+2)]
    for i in range(n+2):
        for j in range(n+2):
            if i!=j:
                d = abs(dist[i][0]-dist[j][0])+abs(dist[i][1]-dist[j][1])
                graph[i][j] = INF if d > 1000 else d
    for k in range(n+2):
        for i in range(n+2):
            for j in range(n+2):
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j])
    print("sad" if graph[0][n+1]==INF else "happy")