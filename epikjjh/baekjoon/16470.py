import sys

input = lambda: sys.stdin.readline().rstrip()
p = dict()
for i in range(100000):
    tmp = input()
    if not tmp:
        break
    if tmp in p:
        p[tmp] += 1
    else:
        p[tmp] = 1
s = 0
for e in p.values():
    div = (e/i)**2
    s += div
print(1-s)