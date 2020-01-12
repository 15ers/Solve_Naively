n = int(input())
cur,pre=1,0
mod = 1000000
p = mod//10*15
for i in range(n%p):
    cur,pre=pre,(cur+pre)%1000000
print(pre)