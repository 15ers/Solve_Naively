def trans(intensity):
    if 0<=intensity<510000:
        return chr(35)
    elif 510000<=intensity<1020000:
        return chr(111)
    elif 1020000<=intensity<1530000:
        return chr(43)
    elif 1530000<=intensity<2040000:
        return chr(45)
    else:
        return chr(46)


n,m = map(int,input().split())
intensity_map = [[0]*m for i in range(n)] 
for y in range(n):
    stream = list(map(int,input().split()))
    for x in range(m):
        i = 2126*stream[3*x] + 7152*stream[3*x+1] + 722*stream[3*x+2]
        intensity_map[y][x] = trans(i)
for elem in intensity_map:
    for e in elem:
        print(e,end="")
    print()