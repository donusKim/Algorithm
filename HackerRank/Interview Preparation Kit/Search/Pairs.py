#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the pairs function below.
def pairs(k, arr):
    numDict={}
    ans=0
    for num in arr:
        if num in numDict:
            numDict[num]+=1
        else:
            numDict[num]=1
    for num in numDict:
        if num-k in numDict:        
            ans+=numDict[num]*numDict[num-k]
    return ans
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    arr = list(map(int, input().rstrip().split()))

    result = pairs(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
