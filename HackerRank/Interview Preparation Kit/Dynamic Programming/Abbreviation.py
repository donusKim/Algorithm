#!/bin/python3

import math
import os
import random
import re
import sys
sys.setrecursionlimit(15000)
# Complete the abbreviation function below.
def abbreviation(a, b):
    a=list(a)
    b=list(b)
    aLen=len(a)
    bLen=len(b)
    aDict={}
    bDict={}
    ## 대문자 구성에 대한 check
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
    for letter in aDict:
        if letter.isupper() and (letter not in bDict or aDict[letter]>bDict[letter]):
            return "NO"

    dp=[[-1 for x in range(bLen)] for x in range(aLen)]
    if checkMatch(a,b,aLen-1,bLen-1,dp)>0:
        return "YES"
    else:
        return "NO"






def checkMatch(a,b,aIdx,bIdx,dp):
    aLen=len(a)
    bLen=len(b)
    if bIdx<0:
        return 1
    if aIdx<bIdx:
        return 0
    if dp[aIdx][bIdx]>-1:
        return dp[aIdx][bIdx]
    
    # 두문자가 대문자이면서 같을때
    if a[aIdx]==b[bIdx]:
        dp[aIdx][bIdx]=checkMatch(a,b,aIdx-1,bIdx-1,dp)+checkMatch(a,b,aIdx-1,bLen-1,dp)
        return dp[aIdx][bIdx]
    # 두문자가 하나는소문자이면서 같을때
    if a[aIdx].upper()==b[bIdx]:
        dp[aIdx][bIdx]=checkMatch(a,b,aIdx-1,bIdx-1,dp)+checkMatch(a,b,aIdx-1,bIdx,dp)
        return dp[aIdx][bIdx]
    if a[aIdx].isupper():
        dp[aIdx][bIdx]=checkMatch(a,b,aIdx-1,bLen-1,dp)
    else:
        dp[aIdx][bIdx]=checkMatch(a,b,aIdx-1,bIdx,dp)
    return dp[aIdx][bIdx]
  
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        a = input()

        b = input()

        result = abbreviation(a, b)

        fptr.write(result + '\n')

    fptr.close()
