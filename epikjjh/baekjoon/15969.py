import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
scores = [*map(int, input().split())]
print(max(scores) - min(scores))