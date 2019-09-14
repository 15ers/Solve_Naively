cap=[0]*3;amt=[0]*3
for i in range(3):
    ci,ai = map(int,input().split())
    cap[i]=ci;amt[i]=ai
for i in range(100):
    total = amt[i%3]+amt[(i+1)%3]
    amt[(i+1)%3] = min(total,cap[(i+1)%3])
    amt[i%3] = total-amt[(i+1)%3]
for e in amt:
    print(e)