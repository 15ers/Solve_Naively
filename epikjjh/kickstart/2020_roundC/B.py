import sys

input = lambda: sys.stdin.readline()

tc = int(input())
for t in range(1,tc+1):
    r,c = map(int,input().split())
    arr = [input().rstrip() for i in range(r)]
    uniques = list(set([arr[i][j] for i in range(r) for j in range(c)]))
    indegree = {uc:0 for uc in uniques}
    adj = {uc:[] for uc in uniques}
    for uc in uniques:
        for i in range(r):
            for j in range(c):
                if i!=r-1 and arr[i][j]==uc and arr[i+1][j]!=uc:
                    tar = arr[i+1][j]
                    if uc not in adj[tar]:
                        indegree[uc] += 1 
                        adj[tar].append(uc)
    queue = [key for key,val in indegree.items() if val==0]
    ans = []
    while len(queue)!=0:
        cur = queue.pop(0)
        ans.append(cur)
        for nxt in adj[cur]:
            indegree[nxt] -= 1
            if indegree[nxt]==0:
                queue.append(nxt)
    ans = "".join(ans)
    if len(ans) != len(uniques):
        ans = -1         
    print("Case #{}: {}".format(t,ans))
