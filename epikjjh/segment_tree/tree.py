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