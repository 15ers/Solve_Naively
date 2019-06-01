num = int(input())
seq = list(map(int, input().split()))
cache = [0] * num


def lis(start):
    if cache[start]:
        return cache[start]
    cache[start] = 1
    for nxt in range(start+1, num):
        if seq[nxt] > seq[start]:
            cache[start] = max(cache[start], lis(nxt)+1)
    return cache[start]


max_len = 1
for i in range(num):
    max_len = max(max_len, lis(i))
print(max_len)