def check(r,c):
    for elem in direction:
        if stage[r+elem[0]][c+elem[1]]:
            return False
    return True

def mark(r,c):
    for elem in direction:
        stage[r+elem[0]][c+elem[1]] = 1
        
def unmark(r,c):
    for elem in direction:
        stage[r+elem[0]][c+elem[1]] = 0
        
def dfs(c_r,n,cnt):
    global ans
    if cnt == 3:
        p_ans = sum([prices[r][c] for r in range(n) for c in range(n) if stage[r][c]])
        ans.append(p_ans)
    else:
        for r in range(c_r,n-1):
            for c in range(1,n-1):
                if check(r,c):
                    mark(r,c)
                    dfs(r,n,cnt+1)
                    unmark(r,c)
    
n = int(input())
prices = [list(map(int,input().split())) for i in range(n)]
stage = [[0]*n for i in range(n)]
direction = ((0,0), (1,0), (-1,0), (0,-1), (0,+1))
ans = []
dfs(1,n,0)
print(min(ans))