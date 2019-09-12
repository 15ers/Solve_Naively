def check(table):
    n = len(table)
    for i in range(n):
        if table[i] != table[(i+1)%n]:
            return False
    return True


t = int(input())
for i in range(t):
    n = int(input())
    table = list(map(int,input().split()))
    l = len(table)
    cnt = 0
    table = [e+1 if e%2==1 else e for e in table]
    while not check(table):
        table = [table[i]//2 + table[(i+1)%l]//2 for i in range(l)]
        table = [e+1 if e%2==1 else e for e in table]
        cnt += 1
    print(cnt)