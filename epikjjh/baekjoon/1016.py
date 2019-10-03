import math

min,max = map(int,input().split())
sieve = [i for i in range(min,max+1)]
cnt = len(sieve)
end = int(math.sqrt(max))
for i in range(2,end+1):
    num = i*i
    mod = min%num
    ind = 0 if not mod else num-mod
    for j in range(ind,len(sieve),num):
        if sieve[j]:
            cnt -= 1
            sieve[j] = 0
print(cnt)