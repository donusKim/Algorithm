#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countTriplets function below.
def countTriplets(arr, r):
    arrLen=len(arr)
    numDict={}
    rDict={}
    rrDict={}
    ans=0
    ## 3개의 사전을 채워나갈 것
    for num in range(arrLen):
        if arr[num] in numDict:
            numDict[arr[num]]+=1
        else:
            numDict[arr[num]]=1
        if arr[num]%r<1 and arr[num]//r in numDict:
            if arr[num] in rDict:
                rDict[arr[num]]+=numDict[arr[num]//r]
            else:
                rDict[arr[num]]=numDict[arr[num]//r]
        if arr[num]%(r*r)<1 and arr[num]//r in rDict:
            if arr[num] in rrDict:
                rrDict[arr[num]]+=rDict[arr[num]//r]
            else:
                rrDict[arr[num]]=rDict[arr[num]//r]

    if r>1:
        for num in rrDict:
            ans+=rrDict[num]
            
    else:
        for num in numDict:
            if(numDict[num]>2):
                ans+=numDict[num]*(numDict[num]-1)*(numDict[num]-2)//6

    return ans
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nr = input().rstrip().split()

    n = int(nr[0])

    r = int(nr[1])

    arr = list(map(int, input().rstrip().split()))

    ans = countTriplets(arr, r)

    fptr.write(str(ans) + '\n')

    fptr.close()
