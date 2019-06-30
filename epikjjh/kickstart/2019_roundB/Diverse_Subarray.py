import math
import sys

input = sys.stdin.readline


class SegmentTree:
    def __init__(self, arr):
        def build_sum(self, arr, node, start, end):
            if start != end:
                self.tree[node] = build_sum(self, arr, node*2, start, (start+end)//2) + build_sum(self, arr, node*2+1, (start+end)//2+1, end)
                return self.tree[node]
            else:
                self.tree[node] = arr[start]
                return self.tree[node]

        def build_prefix(self, node, start, end):
            if start != end:
                self.prefix[node] = max(build_prefix(self, node*2, start, (start+end)//2), self.tree[node*2]+build_prefix(self, node*2+1, (start+end)//2+1, end))
                return self.prefix[node]
            else:
                self.prefix[node] = self.tree[node]
                return self.prefix[node]
        height = math.ceil(math.log2(len(arr)))
        self.start = 0
        self.end = len(arr)-1
        self.tree = [0]*2**(height+1)
        self.prefix = [0]*2**(height+1)
        self.leaf = -1
        build_sum(self, arr, 1, self.start, self.end)
        build_prefix(self, 1, self.start, self.end)
        
    def update(self, index, diff):
        def update_sum(self, node, start, end, index, diff):
            if start <= index <= end:
                self.tree[node] += diff
                if start != end:
                    update_sum(self, node*2, start, (start+end)//2, index, diff)
                    update_sum(self, node*2+1, (start+end)//2+1, end, index, diff)
                else:
                    self.leaf = node
            
        def update_prefix(self, node, diff):
            if node > 0:
                if node == self.leaf:
                    self.prefix[node] += diff
                else:
                    self.prefix[node] = max(self.prefix[node*2], self.tree[node*2]+self.prefix[node*2+1])
                update_prefix(self, node//2, diff)
        update_sum(self, 1, self.start, self.end, index, diff)
        update_prefix(self, self.leaf, diff)


test_num = int(input().rstrip())
for test in range(test_num):
    n, s = map(int, input().rstrip().split())
    table = list(map(int, input().rstrip().split()))
    freq = {}
    arr = []
    for idx, elem in enumerate(table):
        if elem not in freq:
            freq[elem] = [idx]
            arr.append(1)
        else:
            freq[elem].append(idx)
            if len(freq[elem]) == s+1:
                arr.append(-s)
            elif len(freq[elem]) > s+1:
                arr.append(0)
            else:
                arr.append(1)
    seg = SegmentTree(arr)
    ans = seg.prefix[1]
    for i in range(n):
        target = table[i]
        for num, idx in enumerate(freq[target]):
            if num == 0:
                diff = -1
            elif num == s:
                diff = s+1
            elif num == s+1:
                diff = -s
            else:
                diff = 0
            if diff:
                seg.update(idx, diff)
        freq[target].pop(0)
        ans = max(ans, seg.prefix[1])
    print("Case #{0}: {1}".format(test+1, ans))