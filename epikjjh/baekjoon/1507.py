from functools import reduce
from copy import deepcopy

n = int(input())
cost = [list(map(int,input().split())) for i in range(n)]
d_cost = deepcopy(cost)
for k in range(n):
    for i in range(n):
        for j in range(n):
            if i==k or j==k or i==j:
                continue
            elif cost[i][j] > cost[i][k]+cost[k][j]:
                print(-1)
                break
            elif cost[i][j] == cost[i][k]+cost[k][j]:
                d_cost[i][j] = 0
        else:
            continue
        break
    else:
        continue
    break
else:
    ans = [sum(e) for e in d_cost]
    print(reduce(lambda x,y: x+y,ans)//2)