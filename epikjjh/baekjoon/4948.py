end = 123456*2
sieve = [0]+[1 if i==1 or (i!=0 and i%2==0) else 0 for i in range(end)]
for i in range(3,int(end**0.5)):
    if sieve[i]:
        for j in range(i*i,end+1,i):
            sieve[j] = 0
while True:
    n = int(input())
    if n == 0:
        break
    cnt = 0
    for i in range(n+1,2*n+1):
        if sieve[i]:
            cnt += 1
    print(cnt)
