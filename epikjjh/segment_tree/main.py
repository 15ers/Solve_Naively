import math
from tree import *

if __name__ == "__main__":
    input_num = int(input("Insert input number : "))
    height = math.ceil(math.log2(input_num))
    tree = [0]*2**(height+1)
    stream = input("Initialize segment tree : ")
    arr = list(map(int, stream.split()))
    init(arr, tree, 1, 0, input_num-1)
    while True:
        option = input("""Choose your option : 
        1. Update(U or u)
        2. Sum(S or s)
        """)
        if option == "U" or option == "u":
            index, value = map(int, input("Insert index, value : ").split())
            diff = value - tree[index]
            update(tree, 1, 0, input_num-1, index, diff)
        elif option == "S" or option == "s":
            left, right = map(int, input("Insert range : ").split())
            print(sum(tree, 1, 0, input_num-1, left, right))
        else:
            break