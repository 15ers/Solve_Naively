n,k = map(int,input().split())
table = [int(input()) for i in range(n)]
nxt = 0
for i in range(n):
    if nxt == k:
        print(i)
        break
    nxt = table[nxt]
else:
    print(-1)