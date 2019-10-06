def dfs(idx):
    if idx == len(stream):
        print(*ans)
        return True
    for i in int(stream[idx]),int(stream[idx:idx+2]):
        if 1<=i<=n and not num[i]:
            num[i] = 1
            ans.append(i)
            if dfs(idx+len(str(i))):
                return True
            num[i] = 0
            ans.pop()
        
        
stream = input()
tmp = ""
for n in range(1,51):
    tmp += str(n)
    if len(tmp) == len(stream):
        break
num = [0]*(n+1)
ans = []
dfs(0)