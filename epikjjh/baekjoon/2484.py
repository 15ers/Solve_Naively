n = int(input())
ans = 0
for i in range(n):
    nums = list(map(int,input().split()))
    num = set(nums)
    if len(num) == 1:
        p = 50000+list(num)[0]*5000
    elif len(num) == 2:
        p = 10000+(sum(nums)-sum(num))//2*1000 if sum(nums) - 2*sum(num) else 2000+list(num)[0]*500+list(num)[1]*500
    elif len(num) == 3:
         p = 1000+(sum(nums)-sum(num))*100
    else:
        p = max(nums)*100
    ans = max(ans,p)
print(ans)