import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for i in range(t):
    p = input()
    num = int(input())
    arr = input()[1:-1].split(',')
    r_flag = False
    front = 0
    rear = 0
    for elem in p:
        if elem == "R":
            r_flag = not r_flag
        elif elem == "D" and r_flag:
            rear += 1
        elif elem == "D" and not r_flag:
            front += 1
    if front+rear <= num:
        if r_flag:
            arr = arr[front:num-rear][::-1]
        else:
            arr = arr[front:num-rear]
        print("["+",".join(arr)+"]")
    else:
        print("error")