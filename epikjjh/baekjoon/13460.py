n, m = map(int, input().split())
arr = [list(input()) for j in range(n)]
foot_print = [[[] for i in range(m)] for j in range(n)]
# initialize locations of red, blue
for y in range(1, n-1):
    for x in range(1, m-1):
        if arr[y][x] == "R":
            red_y = y
            red_x = x
        elif arr[y][x] == "B":
            blue_y = y
            blue_x = x
# packing format : [red_x, red_y, blue_x, blue_y, cnt]
queue = [(red_x, red_y, blue_x, blue_y, 0)]


# direction: (x,y)
def move(direction, priority, r_x, r_y, b_x, b_y, cnt):
    # move red
    while(arr[r_y][r_x] != "#" and arr[r_y][r_x] != "O"):
        r_x += direction[0]
        r_y += direction[1]
    if arr[r_y][r_x] == "#":
        r_x -= direction[0]
        r_y -= direction[1]
    # move blue
    while(arr[b_y][b_x] != "#" and arr[b_y][b_x] != "O"):
        b_x += direction[0]
        b_y += direction[1]
    if arr[b_y][b_x] == "#":
        b_x -= direction[0]
        b_y -= direction[1]
    # for overlapping situation
    if arr[r_y][r_x] != "O" and (r_x == b_x and r_y == b_y):
        # red first
        if priority:
            b_x -= direction[0]
            b_y -= direction[1]
        # blue first
        else:
            r_x -= direction[0]
            r_y -= direction[1]
    return (r_x, r_y, b_x, b_y, cnt)


while queue:
    pack = queue[0]
    if pack[-1] > 10:
        break
    cur_r_x, cur_r_y, cur_b_x, cur_b_y, cur_cnt = pack
    if arr[cur_b_y][cur_b_x] == "O":
        queue.pop(0)
        continue
    if (cur_b_x, cur_b_y) in foot_print[cur_r_y][cur_r_x]:
        queue.pop(0)
        continue
    if arr[cur_r_y][cur_r_x] == "O":
        print(cur_cnt)
        break
    foot_print[cur_r_y][cur_r_x].append((cur_b_x, cur_b_y))
    queue.pop(0)
    cur_cnt += 1
    # east & west move
    """
    east : red first
    west : blue first
    """
    if cur_r_x > cur_b_x:
        east = move((1, 0), 1, cur_r_x, cur_r_y, cur_b_x, cur_b_y, cur_cnt)
        west = move((-1, 0), 0, cur_r_x, cur_r_y, cur_b_x, cur_b_y, cur_cnt)
    else:
        east = move((1, 0), 0, cur_r_x, cur_r_y, cur_b_x, cur_b_y, cur_cnt)
        west = move((-1, 0), 1, cur_r_x, cur_r_y, cur_b_x, cur_b_y, cur_cnt)
    # north & south move
    """
    north : blue first
    south : red first
    """
    if cur_r_y > cur_b_y:
        north = move((0, -1), 0, cur_r_x, cur_r_y, cur_b_x, cur_b_y, cur_cnt)
        south = move((0, 1), 1, cur_r_x, cur_r_y, cur_b_x, cur_b_y, cur_cnt)
    else:
        north = move((0, -1), 1, cur_r_x, cur_r_y, cur_b_x, cur_b_y, cur_cnt)
        south = move((0, 1), 0, cur_r_x, cur_r_y, cur_b_x, cur_b_y, cur_cnt)
    # Insert to queue
    queue.extend([east, west, north, south])
if arr[cur_r_y][cur_r_x] != "O" or arr[cur_b_y][cur_b_x] == "O":
    print(-1)