def binary_search(key, arr, left, right):
    if left <= right:
        mid = (left+right) // 2
        if key == arr[mid]:
            return mid
        elif key > arr[mid]:
            left = mid + 1
        else:
            right = mid - 1
        return binary_search(key, arr, left, right)
    else:
        return -1


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


def binary_search_upper(key, arr, left, right):
    if left < right:
        mid = (left+right) // 2
        if key >= arr[mid]:
            left = mid + 1
        else:
            right = mid
        return binary_search_upper(key, arr, left, right)
    else:
        return right