#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countInversions function below.
def countInversions(arr):
    arrLen=len(arr)
    ans=mergeSort(arr,0,arrLen-1)
    return ans
## 바꾸는 횟수를 return
def mergeSort(arr,l,r):
    if(l>=r):
        return 0
    mid=(l+r)//2
    swapCnt=mergeSort(arr,l,mid)+mergeSort(arr,mid+1,r)
    s1=l
    s2=mid+1
    temp=[0 for x in range(r-l+1)]
    idx=0
    while s1<=mid and s2<=r:
        if arr[s1]<=arr[s2]:
            temp[idx]=arr[s1]
            idx+=1
            s1+=1
        else:
            temp[idx]=arr[s2]
            idx+=1
            s2+=1
            ##중요한 파트!! 앞파트 자기보다 큰 수의 개수만큼 더해준다
            
            swapCnt+=mid-l+1-(s1-l)
    while s1<=mid:
        temp[idx]=arr[s1]
        idx+=1
        s1+=1
    while s2<=r:
        temp[idx]=arr[s2]
        idx+=1
        s2+=1
    arr[l:r+1]=temp
    
    return swapCnt



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        result = countInversions(arr)

        fptr.write(str(result) + '\n')

    fptr.close()
