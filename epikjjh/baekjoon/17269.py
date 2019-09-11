import sys

input = lambda: sys.stdin.readline().rstrip()
table = str.maketrans("ABCDEFGHIJKLMNOPQRSTUVWXYZ","32124313113132122212111221")
n,m = map(int, input().split())
a,b = input().split()
name = "".join([e for elem in zip(a,b) for e in elem])+a[min(n,m):]+b[min(n,m):]
trans = [int(i) for i in name.translate(table)]
while len(trans) > 2:
    trans = [(trans[i]+trans[i+1]) % 10 for i in range(len(trans)-1)]
print("{}%".format(trans[0]*10+trans[1]))