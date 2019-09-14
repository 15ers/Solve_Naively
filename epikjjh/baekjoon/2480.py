nums = list(map(int,input().split()))
num = set(nums)
if len(num) == 1:
    print(10000+list(num)[0]*1000)
elif len(num) == 2:
    print(1000+(sum(nums)-sum(num))*100)
else:
    print(max(nums)*100)