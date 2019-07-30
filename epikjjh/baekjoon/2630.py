import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
arr = [list(map(int, input().split())) for i in range(n)]
count = [0, 0]


def divide(arr):
    size = len(arr)
    ret = 0
    for e in arr:
        ret += sum(e)
    if ret == 0:
        count[0] += 1
    elif ret == size*size:
        count[1] += 1
    else:
        first = [elem[:size//2] for elem in arr[:size//2]]
        second = [elem[size//2:] for elem in arr[:size//2]]
        third = [elem[:size//2] for elem in arr[size//2:]]
        fourth = [elem[size//2:] for elem in arr[size//2:]]
        for i in [first, second, third, fourth]:
            divide(i)


divide(arr)
print(count[0])
print(count[1])