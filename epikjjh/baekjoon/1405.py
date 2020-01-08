def search(cnt,p,x,y):
    global s
    if cnt==n:
        s += p
        return
    else:
        check[y][x] += 1
        for i in range(4):
            if i<2:
                nx = x-1 if i else x+1
                if not check[y][nx]:
                    search(cnt+1,p*dir_prob[i]/100,nx,y)
            else:
                ny = y-1 if i%2 else y+1
                if not check[ny][x]:
                    search(cnt+1,p*dir_prob[i]/100,x,ny)
        check[y][x] -= 1
        
                    
n,*dir_prob = map(int,input().split())
check = [[0]*(n+1) for i in range(n+1)]
s = 0
search(0,1,0,0)
print(s)