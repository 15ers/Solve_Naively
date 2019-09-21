squares = []
for _ in range(3):
    x,y = map(int,input().split())
    if x > y:
        x,y = y,x
    squares.append((x,y))
for i in range(3):
    for j in range(2):
        target = squares[i]
        t_x,t_y = target if j else target[::-1]    
        others = squares[:i]+squares[i+1:]
        for k in range(4):
            f_x,f_y = others[0] if k<=1 else others[0][::-1]
            s_x,s_y = others[1] if k%2==1 else others[1][::-1]
            if (t_x==f_x+s_x and f_y==s_y and t_x==t_y+f_y) or (t_y==f_y==s_y and t_y==t_x+f_x+s_x):
                print("YES")
                break
        else:
            continue
        break
    else:
        continue
    break
else:
    print("NO")