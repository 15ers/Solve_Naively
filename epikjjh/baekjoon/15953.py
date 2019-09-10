import sys

input = lambda: sys.stdin.readline().rstrip()

t = int(input())
for i in range(t):
    prize = 0
    a,b = map(int,input().split())
    if a==1:
        prize += 500
    elif 1<a<=3:
        prize += 300
    elif 3<a<=6:
        prize += 200
    elif 6<a<=10:
        prize += 50
    elif 10<a<=15:
        prize += 30
    elif 15<a<=21:
        prize += 10
    else:
        pass
    if b==1:
        prize += 512
    elif 1<b<=3:
        prize += 256
    elif 3<b<=7:
        prize += 128
    elif 7<b<=15:
        prize += 64
    elif 15<b<=31:
        prize += 32
    else:
        pass
    print(prize*10000)