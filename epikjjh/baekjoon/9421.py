from functools import reduce

end = 10000000
sieve = [0]+[1 if i==1 or (i!=0 and i%2==0) else 0 for i in range(end)]
for i in range(3,int(end**0.5)):
    if sieve[i]:
        for j in range(i*i,end+1,i):
            sieve[j] = 0
n = int(input())
for i in range(2,n+1):
    if not sieve[i]:
        continue
    new_num = lambda n: reduce(lambda x,y: int(x)+int(y)**2, '0'+str(n))
    ret = []
    cur = i
    flag = True
    while True:
        nxt = new_num(cur)
        if nxt == 1:
            break
        if nxt in ret:
            flag = False
            break
        ret.append(nxt)
        cur = nxt
    if flag:
        print(i)
