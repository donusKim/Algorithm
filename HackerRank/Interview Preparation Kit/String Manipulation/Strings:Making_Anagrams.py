#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the makeAnagram function below.
def makeAnagram(a, b):
    a=list(a)
    b=list(b)
    aLen=len(a)
    bLen=len(b)
    aDict={}
    bDict={}
    for i in range(aLen):
        if a[i] in aDict:
            aDict[a[i]]+=1
        else:
            aDict[a[i]]=1

    for i in range(bLen):
        if b[i] in bDict:
            bDict[b[i]]+=1
        else:
            bDict[b[i]]=1
    sum=0
    ## a에 있는거에 대해 
    for alpabet in aDict:
        if alpabet in bDict:
            sum+=Abs(aDict[alpabet]-bDict[alpabet])
        else:
            sum+=aDict[alpabet]
    ## b에만 있는거에 대해
    for alpabet in bDict:
        if alpabet not in aDict:
            sum+=bDict[alpabet]
    return sum        

def Abs(a):
    if a>0:
        return a
    else: 
        return a*(-1)

    

    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = input()

    b = input()

    res = makeAnagram(a, b)

    fptr.write(str(res) + '\n')

    fptr.close()
