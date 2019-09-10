import sys

input = lambda: sys.stdin.readline().rstrip()
table = {"A": 3, "B": 2, "C": 1, "D": 2, "E": 4, "F": 3, "G": 1, "H": 3, "I": 1, "J": 1, "K": 3, "L": 1, "M": 3, "N": 2, 
        "O": 1, "P": 2, "Q": 2, "R": 2, "S": 1, "T": 2, "U": 1, "V": 1, "W": 1, "X": 2, "Y": 2, "Z": 1}
n,m = map(int, input().split())
a,b = input().split()
name = [e for elem in zip(a,b) for e in elem]
if n > m:
    name += a[m:]
elif n < m:
    name += b[n:]
trans = [table[e] for e in name]
while len(trans) > 2:
    tmp = []
    for i in range(len(trans)-1):
        ret = (trans[i]+trans[i+1]) % 10
        tmp.append(ret)
    trans = tmp
print("{}%".format(trans[0]*10+trans[1]))