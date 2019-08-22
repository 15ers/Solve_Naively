import sys

input = lambda: sys.stdin.readline().rstrip()
stream = input()
reverse = stream[::-1]
ans = len(stream) if stream != reverse else (len(stream)-1 if stream[1:]!=reverse[:-1] else -1)
print(ans)