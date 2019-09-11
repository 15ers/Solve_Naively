n = int(input())
stream = input()
ans = 0
bonus = 0
for i,e in enumerate(stream):
    if e == "X":
        bonus = 0
    else:
        ans += (i+1)+bonus
        bonus += 1
print(ans)
        