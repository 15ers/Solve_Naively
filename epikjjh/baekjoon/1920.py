n = int(input())
table = set(map(int,input().split()))
m = int(input())
target = map(int,input().split())
for e in target:
    print(1) if e in table else print(0)