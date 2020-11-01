#!/bin/python3

import math
import os
import random
import re
import sys
sys.setrecursionlimit(1500000)
# Complete the maxSubsetSum function below.
def maxSubsetSum(arr):
    arrLen=len(arr)
    dp=[0 for x in range(arrLen)]
    for i in range(arrLen):
        if(i==0):
            dp[i]=arr[i]
        elif(i==1):
            dp[i]=Max(arr[i],arr[i-1])
        else:
            dp[i]=Max(Max(Max(dp[i-1],dp[i-2]),dp[i-2]+arr[i]),arr[i])
    return dp[arrLen-1]


def Max(a,b):
    if a>b:
        return a
    else:
        return b    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = maxSubsetSum(arr)

    fptr.write(str(res) + '\n')

    fptr.close()
