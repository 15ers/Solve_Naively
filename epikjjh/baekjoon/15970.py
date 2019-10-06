import sys

input = sys.stdin.readline
n = int(input())
dots = [[] for _ in range(5000)]
for _ in range(n):
    x,y = map(int,input().split())
    dots[y-1].append(x)
ans = 0
for i in range(5000):
    if dots[i]:
        dots[i].sort()
        for j in range(len(dots[i])):
            if j==0:
                ans += dots[i][j+1]-dots[i][j]
            elif j==len(dots[i])-1:
                ans += dots[i][j]-dots[i][j-1]
            else:
                ans += min(dots[i][j]-dots[i][j-1],dots[i][j+1]-dots[i][j])
print(ans)