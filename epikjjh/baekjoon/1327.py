n,k = map(int,input().split())
arr = list(input().split())
ans = sorted(arr)
cnt = -1
queue = [(0,arr[:])]
visited = set()
visited.add("".join(arr))
while queue:
    c,tar = queue.pop(0)
    if tar == ans:
        cnt = c
        break
    for i in range(n-k+1):
        tmp = tar[i:i+k]
        nxt = tar[:i]+tmp[::-1]+tar[i+k:]
        if "".join(nxt) not in visited:
            visited.add("".join(nxt))
            queue.append((c+1,nxt))
print(cnt)