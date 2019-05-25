import math

n = int(input())
people = list(map(int, input().split()))
first, second = list(map(int, input().split()))
ans = n
for i in range(n):
    people[i] -= first
    if people[i] > 0:
        ans += math.ceil(people[i] / second)
print(ans)