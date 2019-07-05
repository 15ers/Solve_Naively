import math

n = int(input())
for i in range(n):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    distance = math.sqrt((x1-x2)**2 + (y1-y2)**2)
    if distance > r1+r2:
        print(0)
    elif distance == r1+r2:
        print(1)
    # distance < r1+r2
    else:
        if r1 == r2:
            if distance == 0:
                print(-1)
            else:
                print(2)
        else:
            if r2 > r1:
                r1, r2 = r2, r1
            if r1-r2 == (distance):
                print(1)
            elif distance < r1-r2:
                print(0)
            else:
                print(2)