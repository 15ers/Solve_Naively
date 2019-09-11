import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
stream = list(map(int, input().split()))
p_sum = [0]+[stream[i]*(i+1) for i in range(n)]
ans = [p_sum[i+1]-p_sum[i] for i in range(n)]
print(*ans)