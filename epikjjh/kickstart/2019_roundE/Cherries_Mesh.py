import sys


def dfs(visited, graph, index, group):
    if not visited[index]:
        visited[index] = 1
        for i,elem in enumerate(graph[index]):
            if elem:
                group.add(i)
                dfs(visited, graph, i, group)
                visited[i] = 1

                
input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for test in range(t):
    n, m = map(int, input().split())
    graph = [[0 for i in range(n+1)]for j in range(n+1)]
    visited = [0 for i in range(n+1)]
    for i in range(m):
        a, b = map(int, input().split())
        graph[a][b] = graph[b][a] = 1
    group = []
    for i in range(1,n+1):
        if not visited[i]:
            i_group = {i}
            dfs(visited, graph, i, i_group)
            group.append(i_group)
    ans = 0
    for elem in group:
        ans += len(elem)-1
    ans += (len(group)-1)*2
    print("Case #{0}: {1}".format(test+1, ans))