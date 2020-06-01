import sys

input = lambda: sys.stdin.readline().rstrip()
end = 1299709
sieve = [0]+[1 if i==1 or (i!=0 and i%2==0) else 0 for i in range(end)]
for i in range(3,int(end**0.5)):
    if sieve[i]:
        for j in range(i*i,end+1,i):
            sieve[j] = 0
t = int(input())
for i in range(t):
    n = int(input())
    if sieve[n]:
        print(0)
        continue
    s = e = -1
    for j in range(n-1,1,-1):
        if sieve[j]:
            s = j
            break
    for j in range(n+1,end+1):
        if sieve[j]:
            e = j
            break
    print(e-s)
