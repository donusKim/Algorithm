#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the candies function below.
def candies(n, arr):
    ans=0
    left=[0 for x in range(n)]
    right=[0 for x in range(n)]
    consecutiveCnt=0
    for i in range(1,n):
        if arr[i]>arr[i-1]:
            consecutiveCnt+=1
            left[i]=consecutiveCnt
        else:
            consecutiveCnt=0
    for i in range(1,n):
        if arr[n-i]<arr[n-i-1]:
            consecutiveCnt+=1
            right[n-i-1]=consecutiveCnt
        else:
            consecutiveCnt=0
    for i in range(n):
        ans+=Max(left[i],right[i])
    return ans+n
def Max(a,b):
    if a>b:
        return a
    else:
        return b


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = []

    for _ in range(n):
        arr_item = int(input())
        arr.append(arr_item)

    result = candies(n, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
