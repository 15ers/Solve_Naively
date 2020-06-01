import sys

input = lambda: sys.stdin.readline().rstrip()
end = 1000000
sieve = [0]+[1 if i==1 or (i!=0 and i%2==0) else 0 for i in range(end)]
for i in range(3, int(end**0.5)):
    if sieve[i]:
        for j in range(i*i,end+1,i):
            sieve[j] = 0
while True:
    n = int(input())
    if n == 0:
        break
    for i in range(3, n, 2):
        if sieve[i] and sieve[n-i]:
            print("{} = {} + {}".format(n, i, n-i)) 
            break
