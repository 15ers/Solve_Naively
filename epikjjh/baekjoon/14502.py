import sys
import copy

input = lambda: sys.stdin.readline().rstrip()


def diffusion(scenario):
    dx = (-1,1,0,0)
    dy = (0,0,-1,1)
    queue = virus[:]
    while queue:
        x,y = queue.pop(0)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<m and 0<=ny<n and not scenario[ny][nx]:
                scenario[ny][nx] = 2
                queue.append((nx,ny))

def comb(i,depth):
    global ans
    if depth == 3:
        scenario = copy.deepcopy(lab)
        diffusion(scenario)
        partial_ans = 0
        for elem in scenario:
            partial_ans += elem.count(0)
        ans = max(ans, partial_ans)
    else:
        for j in range(i,n*m):
            if not lab[j//m][j%m]:
                lab[j//m][j%m] = 1
                comb(j+1,depth+1)
                lab[j//m][j%m] = 0           
            
            
ans = 0
direction = ((0,1),(0,-1),(1,0),(-1,0))
n, m = map(int, input().split())
lab = [list(map(int, input().split())) for i in range(n)]
virus = [(i%m,i//m) for i in range(n*m) if lab[i//m][i%m]==2]        
comb(0,0)
print(ans)