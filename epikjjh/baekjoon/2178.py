import sys

def conv(stream):
    return [int(e) for e in stream]
        

input = sys.stdin.readline
n,m = map(int,input().split())
arr = [conv(input().split()[0]) for i in range(n)]
visit = [[0]*m for i in range(n)]
visit[0][0] = 1
direction = [(0,1),(0,-1),(1,0),(-1,0)]
queue = [[0,0]]
while queue:
    y,x = queue.pop(0)
    if y==n-1 and x==m-1:
        print(visit[y][x])
        break
    for i in range(4):
        n_y = y+direction[i][0]
        n_x = x+direction[i][1]
        if 0<=n_y<n and 0<=n_x<m and arr[n_y][n_x] and not visit[n_y][n_x]:
            visit[n_y][n_x] = visit[y][x] + 1
            queue.append([n_y,n_x])