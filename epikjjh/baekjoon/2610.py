import sys

def find_num(cycle):
    if len(cycle)==1:
        return cycle[0]+1
    ret = {}
    for i in cycle:
        p_sum = max([graph[i][j] for j in cycle if i!=j])
        ret[i] = p_sum
    ret = sorted(ret,key=lambda x:ret[x])
    return ret[0]+1


INF = 987654321
input = sys.stdin.readline
n = int(input())
graph = [[INF if i!=j else 0 for j in range(n)]for i in range(n)]
m = int(input())
for _ in range(m):
    a,b = map(int,input().split())
    graph[a-1][b-1] = graph[b-1][a-1] = 1
for k in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j])
committee = [[j for j in range(n) if graph[i][j]!=INF] for i in range(n)]
ans = []
for elem in committee:
    if elem not in ans:
        ans.append(elem)
rep = sorted(list(map(find_num,ans)))
print(len(ans))
print(*rep,sep='\n')