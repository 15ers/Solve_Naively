n, m, start = map(int, input().split())
matrix = [[0]*(n+1) for i in range(n+1)]
flag = [0]*(n+1)
queue = [start]
for i in range(m):
    a, b = map(int, input().split())
    matrix[a][b] = matrix[b][a] = 1


def dfs(vertex):
    if not flag[vertex]:
        print(vertex, end=" ")
        flag[vertex] = 1
        for i in range(1, n+1):
            if matrix[vertex][i]:
                dfs(i)


dfs(start)
print()
flag = [0]*(n+1)
while queue:
    vertex = queue.pop(0)
    if not flag[vertex]:
        print(vertex, end=" ")
        flag[vertex] = 1
        for i in range(1, n+1):
            if matrix[vertex][i]:
                queue.append(i)
print()