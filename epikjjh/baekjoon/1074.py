def divide(n,r,c,cnt,t_r,t_c):
    if n == 1:
        for i in range(4):
            if r+order[i][0]==t_r and c+order[i][1]==t_c:
                print(cnt+i)
    else:
        for i in range(4):
            n_r = r+order[i][0]*2**(n-1)
            n_c = c+order[i][1]*2**(n-1)
            n_cnt = cnt+2**(2*(n-1))*i
            if n_r<=t_r<n_r+2**(n-1) and n_c<=t_c<n_c+2**(n-1):
                divide(n-1,n_r,n_c,n_cnt,t_r,t_c)
            

order = [(0,0), (0,1), (1,0), (1,1)]
n,r,c = map(int,input().split())
divide(n,0,0,0,r,c)