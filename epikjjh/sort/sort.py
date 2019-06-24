def selection_sort(arr: list):
    for i in range(len(arr)-1, 0, -1):
        max_index = i
        for j in range(i):
            if max_elem < arr[j]:
                max_index = j
        arr[i], arr[max_index] = arr[max_index], arr[i]


def insertion_sort(arr: list):
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            if arr[j] < arr[j-1]:
                arr[j], arr[j-1] = arr[j-1], arr[j]


def bubble_sort(arr: list):
    for i in range(len(arr)-1, 0, -1):
        for j in range(i):
            if arr[j+1] < arr[j]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


def merge(arr: list, left: int, mid: int, right: int):
    tmp = []
    left_index = left
    right_index = mid+1
    while left_index <= mid and right_index <= right:
        if arr[left_index] < arr[right_index]:
            tmp.append(arr[left_index])
            left_index += 1
        else:
            tmp.append(arr[right_index])
            right_index += 1
    if left_index > mid:
        for idx in range(right_index, right+1):
            tmp.append(arr[idx])
    else:
        for idx in range(left_index, mid+1):
            tmp.append(arr[idx])
    arr[left:right+1] = tmp[:]


def merge_sort(arr: list, left: int, right: int):
    if left < right:
        mid = (left+right) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid+1, right)
        merge(arr, left, mid, right)


def quick_sort_outplace(arr: list, left: int, right: int):
    if left < right:
        pivot = arr[(left+right) // 2]
        tmp = arr[left:right+1]
        tmp_left = [elem for elem in tmp if elem < pivot]
        tmp_equal = [elem for elem in tmp if elem == pivot]
        tmp_right = [elem for elem in tmp if elem > pivot]
        arr[left:right+1] = tmp_left + tmp_equal + tmp_right
        quick_sort_outplace(arr, left, left+len(tmp_left)-1)
        quick_sort_outplace(arr, right-len(tmp_right)+1, right)


def quick_sort_inplace(arr: list, left: int, right: int):
    if left < right:
        low = left
        high = right
        pivot = arr[(low+high)//2]
        while low <= high:
            while arr[low] < pivot:
                low += 1
            while arr[high] > pivot:
                high -= 1
            if low <= high:
                arr[low], arr[high] = arr[high], arr[low]
                low, high = low + 1, high - 1
        quick_sort_inplace(arr, left, low-1)
        quick_sort_inplace(arr, low, right)


def heapify(tree: list, idx: int, length: int):
    max_idx = idx
    left_idx = 2*idx + 1
    right_idx = 2*idx + 2
    if left_idx < length and tree[left_idx] > tree[max_idx]:
        max_idx = left_idx
    if right_idx < length and tree[right_idx] > tree[max_idx]:
        max_idx = right_idx
    if max_idx != idx:
        tree[idx], tree[max_idx] = tree[max_idx], tree[idx]
        heapify(tree, max_idx, length)


def heap_sort(arr: list):
    n = len(arr)
    for idx in range((n//2)-1, -1, -1):
        heapify(arr, idx, n)
    for i in range(n-1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, 0, i)