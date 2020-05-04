import numpy as np
import sys
sys.setrecursionlimit(100000)

#dp = [[0 for col in range(11)] for row in range(10)]
dp = np.zeros((101,101,2))

def func(start,end,arr):
    if start==end:
        dp[start][end][0]= int(arr[2*start])
        dp[start][end][1]= int(arr[2*start])
        return int(arr[2*start])
    sum1 = -1000000
    sum2 = 1000000
    for i in range(start,end):
        tmpone =0
        tmptwo =0
        left_max= dp[start][i][0]
        right_max = dp[i+1][end][0]
        if left_max ==0:
            left_max = func(start,i,arr)
            dp[start][i][0] = left_max
        if right_max ==0:
            right_max = func(i+1,end,arr)
            dp[i+1][end][0] = right_max
        right_min = dp[i+1][end][1]
        left_min = dp[start][i][1]
    
        if arr[2*i +1]=="-":
            tmpone = left_max - right_min
            tmptwo = left_min - right_max
        else:
            tmpone = left_max + right_max
            tmptwo = left_min + right_min
        
        sum1 = max(sum1, tmpone)
        sum2 = min(sum2,tmptwo)
    
    dp[start][end][1] = min(sum1,sum2)
    dp[start][end][0]=  max(sum1,sum2)
    return dp[start][end][0]


def solution(arr):    
    return func(0,int(len(arr)/2),arr)
