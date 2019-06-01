num = int(input())
seq = list(map(int, input().split()))
cache = [0]*num


def lis(start):
    if cache[start]:
        return cache[start]
    cache[start] = seq[start]
    for nxt in range(start+1, num):
        if seq[start] < seq[nxt]:
            cache[start] = max(cache[start], lis(nxt)+seq[start])
    return cache[start]


max_num = 0
for i in range(num):
    max_num = max(max_num, lis(i))
print(max_num)