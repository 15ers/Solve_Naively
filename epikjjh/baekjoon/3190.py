map_size = int(input())
cur_map = [['#' for i in range(map_size)] for j in range(map_size)]
apple_num = int(input())
# location : y x
apple_location = [tuple(map(int, input().split())) for i in range(apple_num)]
for i in apple_location:
    cur_map[i[0]-1][i[1]-1] = 'O'
turning_num = int(input())
# turningpoint  : (sec, 'L' or 'D')
turning_point = [tuple(input().split()) for i in range(turning_num)]
# location : y x
cur_head = [0, 0]
cur_map[0][0] = '.'
# direction : y x
cur_direction = [0, 1]
cur_length = 1
cur_sec = 0
# interchange : ((interchange_y, interchange_x), (direction_y, direction_x))
interchange = []
while(True):
    apple = 0
    # increase time
    cur_sec += 1
    # Move
    # move head first
    cur_head[0] += cur_direction[0]
    cur_head[1] += cur_direction[1]
    # out of range : game over
    if cur_head[0] >= map_size or cur_head[1] >= map_size or cur_head[0] < 0 or cur_head[1] < 0:
        print(cur_sec)
        break
    # for breaking into her own body : game over
    if cur_map[cur_head[0]][cur_head[1]] == '.':
        print(cur_sec)
        break
    # check if it is apple
    if cur_map[cur_head[0]][cur_head[1]] == 'O':
        cur_length += 1
        apple = 1
    cur_map[cur_head[0]][cur_head[1]] = '.'
    # find tail and move it
    if not apple:
        inter = cur_head[:]
        tmp_copy = interchange[:]
        tmp_bool = False
        if tmp_copy:
            tmp_bool = True
            cmp, next_forward = tmp_copy.pop()
        forward = cur_direction[:]
        for i in range(cur_length):
            inter[0] -= forward[0]
            inter[1] -= forward[1]
            if tmp_bool and (tuple(inter) == cmp):
                forward = next_forward[:]
                if tmp_copy:
                    cmp, next_forward = tmp_copy.pop()
                else:
                    tmp_bool = False
        # if tail reaches one of interchanges, pop it out
        if interchange and (tuple(inter) == interchange[0][0]):
            interchange.pop(0)
        cur_map[inter[0]][inter[1]] = '#'
    # change direction if it is needed
    if turning_point and (cur_sec == int(turning_point[0][0])):
        interchange.append(((cur_head[0], cur_head[1]), (cur_direction[0], cur_direction[1])))
        # turn to left
        '''
        north (-1, 0) -> west (0, -1)
        south (1, 0) -> east (0, 1)
        west (0, -1) -> south (1, 0)
        east(0, 1) -> north (-1, 0)
        '''
        # turn to right
        '''
        north (-1, 0) -> east (0, 1)
        south (1, 0) -> west (0, -1)
        west (0, -1) -> north (-1, 0)
        east(0, 1) -> south (1, 0)
        '''
        if turning_point[0][1] == 'L':
            if cur_direction[0]:
                tmp = cur_direction[0]
                cur_direction[0] = 0
                cur_direction[1] = tmp
            else:
                tmp = cur_direction[1]
                cur_direction[1] = 0
                cur_direction[0] = -tmp
        else:
            if cur_direction[0]:
                tmp = cur_direction[0]
                cur_direction[0] = 0
                cur_direction[1] = -tmp
            else:
                tmp = cur_direction[1]
                cur_direction[1] = 0
                cur_direction[0] = tmp
        turning_point.pop(0)