'''
def perm(n,cand,ret):
    global perms
    if len(ret) == n:
        perms.append(ret[:])
        return
    for i,e in enumerate(cand):
        cand = cand[:i]+cand[i+1:]
        ret.append(e)
        perm(n,cand,ret)
        cand = cand[:i]+[e]+cand[i:]
        ret.pop()

        
n = int(input())
forms = [input() for i in range(n)]
alpha = list({i for form in forms for i in form})
cnt = len(alpha)
nums = [0]*26
for form in forms:
    for i,e in enumerate(form):
        nums[ord(e)-ord('A')] += 10**(len(form)-i-1)
nums = [i for i in nums if i]
perms = []
perm(cnt,[i for i in range(10)],[])
max_sum = 0
for cand in perms:
    ps = sum([nums[i]*cand[i] for i in range(cnt)])
    max_sum = max(max_sum,ps)
print(max_sum)
'''
n = int(input())
nums = [0]*26
for form in [input() for i in range(n)]:
    for i,e in enumerate(form):
        nums[ord(e)-ord('A')] += 10**(len(form)-i-1)
nums.sort(reverse=True)
ret = 0
for i in range(10):
    ret += nums[i]*(9-i)
print(ret)