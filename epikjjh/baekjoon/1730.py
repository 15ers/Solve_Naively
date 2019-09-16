n = int(input())
order = input()
plate = [["."]*n for i in range(n)]
r,c = 0,0
direction = ["U", "D", "L", "R"]
location = ((-1,0), (1,0), (0,-1), (0,1))
for e in order:
    i = direction.index(e)
    n_r = r+location[i][0]
    n_c = c+location[i][1]
    if 0<=n_r<n and 0<=n_c<n:
        if 0<=i<=1:
            plate[r][c] = "+" if plate[r][c]=="-" or plate[r][c]=="+" else "|"
            plate[n_r][n_c] = "+" if plate[n_r][n_c]=="-" or plate[n_r][n_c]=="+" else "|"
        else:
            plate[r][c] = "+" if plate[r][c]=="|" or plate[r][c]=="+" else "-"
            plate[n_r][n_c] = "+" if plate[n_r][n_c]=="|" or plate[n_r][n_c]=="+" else "-"
        r,c = n_r,n_c
for e in plate:
    print("".join(e))
"""
Beautiful solution by boj id cubelover
n = int(input())
a = [[0] * n for _ in range(n)]
x = y = 0
for t in input():
	if t == 'L' and y:
		a[x][y] |= 1
		y -= 1
		a[x][y] |= 1
	if t == 'R' and y + 1 < n:
		a[x][y] |= 1
		y += 1
		a[x][y] |= 1
	if t == 'U' and x:
		a[x][y] |= 2
		x -= 1
		a[x][y] |= 2
	if t == 'D' and x + 1 < n:
		a[x][y] |= 2
		x += 1
		a[x][y] |= 2
print('\n'.join(''.join('.-|+'[t] for t in x) for x in a))
"""