import sys

INF = 987654321
input = sys.stdin.readline
v,e = map(int,input().split())
town = [[INF]*v for i in range(v)]
for _ in range(e):
    a,b,c = map(int,input().split())
    town[a-1][b-1] = min(c,town[a-1][b-1])
for k in range(v):
    for i in range(v):
        for j in range(v):
            town[i][j] = min(town[i][j],town[i][k]+town[k][j])
ans = min([town[i][i] for i in range(v)])
print(-1 if ans == INF else ans)