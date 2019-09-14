def gen(stream):
    stack = []
    tmp = ""
    for e in stream:
        if e == " ":
            if stack:
                tmp += e
            else:
                if tmp:
                    yield tmp[::-1]
                    yield e
                    tmp = ""
        else:
            if e == "<":
                yield tmp[::-1]
                stack.append(e)
                tmp = e
            elif e == ">":
                stack.pop(0)
                tmp += e
                yield tmp
                tmp = ""
            else:
                tmp += e
    if tmp:
        yield tmp[::-1]

                
stream = input()
ans = "".join(list(gen(stream)))
print(ans)