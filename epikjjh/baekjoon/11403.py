INF = 1000
n = int(input())
dist = []
for i in range(n):
    tmp = [0 if e==1 else INF for e in list(map(int,input().split()))]
    dist.append(tmp)
for k in range(n):
    for i in range(n):
        for j in range(n):
            dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j])
for i in range(n):
    for j in range(n):
        print(1 if not dist[i][j] else 0,end=" ")
    print()