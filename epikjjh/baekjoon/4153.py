import sys

input = sys.stdin.readline
a,b,c=sorted(map(int,input().split()))
while(a and b and c):
    print("right") if a**2+b**2==c**2 else print("wrong")
    a,b,c=sorted(map(int,input().split()))