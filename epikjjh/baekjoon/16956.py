rows,cols = map(int,input().split())
stage = [list(input()) for i in range(rows)]
wolves = [(r,c) for r in range(rows) for c in range(cols) if stage[r][c]=="W"]
direction = [(1,0),(-1,0),(0,1),(0,-1)]
flag = True
for wolf in wolves:
    for e in direction:
        r = wolf[0]+e[0]
        c = wolf[1]+e[1]
        if 0<=r<rows and 0<=c<cols:
            if stage[r][c]=="S":
                print(0)
                flag = False
                break
            if stage[r][c]==".":
                stage[r][c] = "D"
    else:
        continue
    break
if flag:
    print(1)
    for e in stage:
        print("".join(e))