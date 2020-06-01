from functools import reduce

ret = [int(reduce(lambda x, y: int(x)+int(y), str(i))) + i for i in range(1,10000)]
for i in range(1,10000):
    if i not in ret:
        print(i)
    
