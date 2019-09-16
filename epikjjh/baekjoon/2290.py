from copy import deepcopy

s,n = input().split()
s = int(s)
n = list(map(int,n))
zero = [[" "]+["-"]*s+[" "] if r==0 or r==2*s+2 else [" "]*(s+2) if r==s+1 else ["|"]+[" "]*s+["|"] for r in range(2*s+3)]
one = [[" "]*(s+2) if r==0 or r==s+1 or r==2*s+2 else [" "]*(s+1)+["|"] for r in range(2*s+3)]
two = [[" "]+["-"]*s+[" "] if r==0 or r==s+1 or r==2*s+2 else [" "]*(s+1)+["|"] if 0<r<s+1 else ["|"]+[" "]*(s+1) for r in range(2*s+3)]
three = [[" "]+["-"]*s+[" "] if r==0 or r==s+1 or r==2*s+2 else [" "]*(s+1)+["|"] for r in range(2*s+3)]
four = [[" "]*(s+2) if r==0 or r==2*s+2 else [" "]+["-"]*s+[" "] if r==s+1 else [" "]*(s+1)+["|"] if s+1<r<2*s+2 else ["|"]+[" "]*s+["|"] for r in range(2*s+3)]
five = [[" "]+["-"]*s+[" "] if r==0 or r==s+1 or r==2*s+2 else ["|"]+[" "]*(s+1) if 0<r<s+1 else [" "]*(s+1)+["|"] for r in range(2*s+3)]
six = [[" "]+["-"]*s+[" "] if r==0 or r==s+1 or r==2*s+2 else ["|"]+[" "]*(s+1) if 0<r<s+1 else ["|"]+[" "]*s+["|"] for r in range(2*s+3)]
seven = [[" "]*(s+2) if r==s+1 or r==2*s+2 else [" "]+["-"]*s+[" "] if r==0 else [" "]*(s+1)+["|"] for r in range(2*s+3)]
eight = [[" "]+["-"]*s+[" "] if r==0 or r==2*s+2 or r==s+1 else ["|"]+[" "]*s+["|"] for r in range(2*s+3)]
nine = [[" "]+["-"]*s+[" "] if r==0 or r==2*s+2 or r==s+1 else [" "]*(s+1)+["|"] if s+1<r<2*s+2 else ["|"]+[" "]*s+["|"] for r in range(2*s+3)]
space = [[" "] for r in range(2*s+3)]
nums = [zero,one,two,three,four,five,six,seven,eight,nine]
ans = deepcopy(nums[n[0]])
for i in range(1,len(n)):
    for j in range(2*s+3):
        ans[j].extend(space[j])
        ans[j].extend(nums[n[i]][j])
for elem in ans:
    print("".join(elem))