def binary_search_lower(key, arr, left, right):
    if left < right:
        mid = (left+right) // 2
        if key > arr[mid]:
            left = mid + 1
        else:
            right = mid
        return binary_search_lower(key, arr, left, right)
    else:
        return right


n = int(input())
arr = list(map(int, input().split()))
ans = [arr[0]]
for i in range(1, n):
    if arr[i] > ans[-1]:
        ans.append(arr[i])
    else:
        idx = binary_search_lower(arr[i], ans, 0, len(ans)-1)
        ans[idx] = arr[i]
print(len(ans))