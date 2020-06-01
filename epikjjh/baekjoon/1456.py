end = 10000000
sieve = [0]+[1 if i==1 or (i!=0 and i%2==0) else 0 for i in range(end)]
for i in range(3,int(end**0.5)):
    if sieve[i]:
        for j in range(i*i,end+1,i):
            sieve[j] = 0
a,b = map(int,input().split())
cnt = 0
for i in range(2,end+1):
    if sieve[i]:
        j = i*i
        while j <= b:
            if a <= j:
                cnt += 1
            j *= i
print(cnt)
