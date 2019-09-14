import re

stream = input()
p = re.compile("<?[^<>]+>?")
ans = ""
for elem in p.findall(stream):
    if elem[0] == "<":
        ans += elem
    else:
        for e in elem.split():
            ans += e[::-1] + " "
        ans = ans.rstrip()
print(ans)