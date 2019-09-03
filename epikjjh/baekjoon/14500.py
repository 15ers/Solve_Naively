import sys

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
stage = [list(map(int, input().split())) for i in range(n)]
path  = [[False]*m for i in range(n)]
direction = ((1,0), (-1,0), (0,1), (0,-1))
def dfs(x,y,p_sum,cnt,path):
    if 0<=x<m and 0<=y<n and not path[y][x]:
        p_sum += stage[y][x]
        if cnt == 4:
            return p_sum
        path[y][x] = True
        ret = 0
        for elem in direction:
            p_ret = dfs(x+elem[1],y+elem[0],p_sum,cnt+1,path)
            if p_ret:
                ret = max(ret, p_ret)
        path[y][x] = False
        return ret
                      
                      
def special(x,y):
    top = down = left = right = -1
    if 1<=x<m-1 and 0<=y<n-1:
        down = stage[y][x] + stage[y][x-1] + stage[y][x+1] + stage[y+1][x]          
    if 1<=x<m-1 and 1<=y<n:
        top = stage[y][x] + stage[y][x-1] + stage[y][x+1] + stage[y-1][x]
    if 1<=x<m and 1<=y<n-1:
        left = stage[y][x] + stage[y][x-1] + stage[y-1][x] + stage[y+1][x]
    if 0<=x<m-1 and 1<=y<n-1:
        right = stage[y][x] + stage[y][x+1] + stage[y-1][x] + stage[y+1][x]
    ret = max(max(max(top, down),left),right)
    return ret


ans = 0
for y in range(n):
    for x in range(m):
        ans_dfs = dfs(x,y,0,1,path)
        ans = max(ans,max(ans_dfs, special(x,y))) if ans_dfs else max(ans,special(x,y))
print(ans)