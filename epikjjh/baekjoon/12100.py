import copy

n = int(input())
# x, y : east, west, south, north
direction = ((1, 0), (-1, 0), (0, 1), (0, -1))
stage = [list(map(int, input().split())) for i in range(n)]
cnt = 0
queue = [(copy.deepcopy(stage), direction[i], cnt) for i in range(4)]


def move(stage, forward, cnt):
    for i in range(n):
        # east & west
        if forward[0]:
            stream = list(filter(lambda x: x > 0, stage[i]))
        # north & south
        else:
            stream = list(filter(lambda x: x > 0, [stage[y][i] for y in range(n)]))
        # north, west : start from fist
        if forward[0] + forward[1] < 0:
            for j in range(len(stream)-1):
                if stream[j] == stream[j+1]:
                    stream[j] += stream[j+1]
                    stream[j+1] = 0
            stream = list(filter(lambda x: x > 0, stream))
            spare = [0]*(n-len(stream))
            if spare:
                stream.extend(spare)
        # south, east : start from last
        else:
            for j in range(len(stream)-1, 0, -1):
                if stream[j] == stream[j-1]:
                    stream[j] += stream[j-1]
                    stream[j-1] = 0
            stream = list(filter(lambda x: x > 0, stream))
            spare = [0]*(n-len(stream))
            if spare:
                spare.extend(stream)
                stream = spare
        if forward[0]:
            stage[i] = stream
        else:
            for y in range(n):
                stage[y][i] = stream[y]
    return [(copy.deepcopy(stage), direction[i], cnt+1) for i in range(4)]


def search(stage):
    ret = 0
    for y in range(n):
        for x in range(n):
            ret = max(stage[y][x], ret)
    return ret


global_max = 0
while queue:
    cur_stage, cur_direction, cur_cnt = queue.pop(0)
    cur_max = search(cur_stage)
    global_max = max(cur_max, global_max)
    if cur_cnt >= 5:
        continue
    pack = move(cur_stage, cur_direction, cur_cnt)
    queue.extend(pack)
print(global_max)