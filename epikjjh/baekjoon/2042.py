import math
import sys


def init(arr: list, tree: list, node: int, start: int, end: int)-> int:
    if start == end:
        tree[node] = arr[start]
        return tree[node]
    else:
        tree[node] = init(arr, tree, node*2, start, (start+end)//2) + init(arr, tree, node*2+1, (start+end)//2+1, end)
        return tree[node]
    
    
def sum(tree: list, node: int, start: int, end: int, left: int, right: int)-> int:
    if right < start or end < left:
        return 0
    elif left <= start and end <= right:
        return tree[node]
    else:
        return sum(tree, node*2, start, (start+end)//2, left, right) + sum(tree, node*2+1, (start+end)//2+1, end, left, right)
    
    
def update(tree: list, node: int, start: int, end: int, index: int, diff: int):
    if index < start or index > end:
        return
    tree[node] += diff
    if start != end:
        update(tree, node*2, start, (start+end)//2, index, diff)
        update(tree, node*2+1, (start+end)//2+1, end, index, diff)
        

input = sys.stdin.readline
num, m, k = map(int, input().rstrip().split())
arr = [int(input().rstrip()) for i in range(num)]
height = math.ceil(math.log2(num))
tree = [0]*2**(height+1)
init(arr, tree, 1, 0, num-1)
for i in range(m+k):
    a, b, c = map(int, input().rstrip().split())
    if a == 1:
        diff = c - (arr[b-1])
        arr[b-1] = c
        update(tree, 1, 0, num-1, b-1, diff)
    else:
        print(sum(tree, 1, 0, num-1, b-1, c-1))