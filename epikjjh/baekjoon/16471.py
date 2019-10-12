n = int(input())
m = sorted(list(map(int,input().split())))
e = sorted(list(map(int,input().split())))
for i in range((n+1)//2):
    if m[i]>=e[i+n//2]:
        print("NO")
        break
else:
    print("YES")