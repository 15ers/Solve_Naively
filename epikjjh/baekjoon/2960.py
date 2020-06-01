n, k = map(int, input().split())
sieve = [0] + [1 for i in range(1,n+1)]
cnt = 0; ret = 0
for i in range(2, n+1):
    if sieve[i]:
        j = i
        while j <= n: 
            if sieve[j]:
                sieve[j] = 0
                cnt += 1
                if cnt == k:
                    ret = j
            j += i
print(ret)
