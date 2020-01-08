import sys


def hanoi(st,mid,ed,sz):
    if sz==1:
        return print(st,ed)
    hanoi(st,ed,mid,sz-1)
    print(st,ed)
    hanoi(mid,st,ed,sz-1)
    
input = sys.stdin.readline
n = int(input())
print(2**n-1)
hanoi(1,2,3,n)