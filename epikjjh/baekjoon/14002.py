n = int(input())
arr = list(map(int, input().split()))
cache = [[] for i in range(n)]
cache[0] = [arr[0]]
ans = len(cache[0])
ans_idx = 0
for i in range(1, n):
    tmp = 0
    tmp_idx = 0
    for j in range(i):
        if arr[i] > arr[j]:
            if tmp < len(cache[j]):
                tmp = len(cache[j])
                tmp_idx = j
    if tmp:
        cache[i][:] = cache[tmp_idx][:] + [arr[i]]
    else:
        cache[i][:] = [arr[i]]
    if ans < len(cache[i]):
        ans = len(cache[i])
        ans_idx = i
print(ans)
print(*cache[ans_idx])