import sys

INF = 987654321
input = sys.stdin.readline
n,r = map(int,input().split())
cities = input().split()
m = int(input())
t_cities = input().split()
trans = int(input())
cost = [[INF if i!=j else 0 for j in range(n)] for i in range(n)]
p_cost = [[INF if i!=j else 0 for j in range(n)] for i in range(n)]
p_free = ["ITX-Saemaeul", "ITX-Cheongchun", "Mugunghwa"]
p_half = ["S-Train", "V-Train"]
for _ in range(trans):
    t,a,b,c = map(lambda x: int(x) if x.isdigit() else x,input().split())
    ind_a = cities.index(a)
    ind_b = cities.index(b)
    cost[ind_a][ind_b] = min(cost[ind_a][ind_b],c)
    cost[ind_b][ind_a] = min(cost[ind_b][ind_a],c)
    if t in p_free:
        c = 0
    elif t in p_half:
        c = c//2
    p_cost[ind_a][ind_b] = min(p_cost[ind_a][ind_b],c)
    p_cost[ind_b][ind_a] = min(p_cost[ind_b][ind_a],c)
for k in range(n):
    for i in range(n):
        for j in range(n):
            cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j])
            p_cost[i][j] = min(p_cost[i][j],p_cost[i][k]+p_cost[k][j])
total = 0
p_total = r
for i in range(1,m):
    ind_s = cities.index(t_cities[i-1])
    ind_e = cities.index(t_cities[i])
    total += cost[ind_s][ind_e]
    p_total += p_cost[ind_s][ind_e]
if p_total < total:
    print("Yes")
else:
    print("No")