n, m, y, x, k = map(int, input().split())
stage = [list(map(int, input().split())) for i in range(n)]
order = list(map(int, input().split()))
'''
 3         3       3        0        5
102       510     025      142      132
 4         4       4        5        0
 5         2       1        3        4
before    east    west    north    south
'''
dice = [0]*6
# direction(y, x) : east, west, north, south
direction = ((0, 1), (0, -1), (-1, 0), (1, 0))


def switch(direction, dice):
    if direction == (0, 1):
        # 5->1 / 1->0 / 0->2 / 2->5
        tmp = dice[:]
        dice[1] = tmp[5]
        dice[0] = tmp[1]
        dice[2] = tmp[0]
        dice[5] = tmp[2]
    elif direction == (0, -1):
        # 0->1 / 2->0 / 5->2 / 1->5
        tmp = dice[:]
        dice[1] = tmp[0]
        dice[0] = tmp[2]
        dice[2] = tmp[5]
        dice[5] = tmp[1]
    elif direction == (-1, 0):
        # 0->3 / 4->0 / 5->4 / 3->5
        tmp = dice[:]
        dice[3] = tmp[0]
        dice[0] = tmp[4]
        dice[4] = tmp[5]
        dice[5] = tmp[3]
    # south : (1, 0)
    else:
        # 5->3 / 3->0 / 0->4 / 4->5
        tmp = dice[:]
        dice[3] = tmp[5]
        dice[0] = tmp[3]
        dice[4] = tmp[0]
        dice[5] = tmp[4]
        

for i in order:
    if 0 <= y + direction[i-1][0] <= n-1 and 0 <= x + direction[i-1][1] <= m-1:
        y += direction[i-1][0]
        x += direction[i-1][1]
        switch(direction[i-1], dice)
        if stage[y][x]:
            dice[5] = stage[y][x]
            stage[y][x] = 0
        else:
            stage[y][x] = dice[5]
            
        print(dice[0])
    else:
        continue