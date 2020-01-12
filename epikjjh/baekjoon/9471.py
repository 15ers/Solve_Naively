t = int(input())
for i in range(t):
    n,m = map(int,input().split())
    c=0
    a,b=1,1
    while True:
        a,b = (a+b)%m,a%m
        c += 1
        if a==1 and b==1:
            break
    print(n,c)