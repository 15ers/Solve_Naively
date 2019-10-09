def dfs(idx,ps):
    global cnt
    if idx == n:
        if ps == s:
            cnt += 1
        return
    dfs(idx+1,ps)
    dfs(idx+1,ps+arr[idx])
    
    
n,s = map(int,input().split())
arr = list(map(int,input().split()))
cnt = 0 if s!=0 else -1
dfs(0,0)
print(cnt)