def sing(num,total):
    if num:
        if num > 1:
            print("{0} bottles of beer on the wall, {1} bottles of beer.".format(num,num))
        else:
            print("1 bottle of beer on the wall, 1 bottle of beer.")
        if num > 2:
            print("Take one down and pass it around, {0} bottles of beer on the wall.".format(num-1))
        elif num == 2:
            print("Take one down and pass it around, 1 bottle of beer on the wall.")
        else:
            print("Take one down and pass it around, no more bottles of beer on the wall.")
    else:
        print("No more bottles of beer on the wall, no more bottles of beer.")
        if total > 1:
            print("Go to the store and buy some more, {0} bottles of beer on the wall.".format(total))
        else:
            print("Go to the store and buy some more, 1 bottle of beer on the wall.")
    print()
        
        
n = int(input())
for i in range(n,-1,-1):
    sing(i,n)