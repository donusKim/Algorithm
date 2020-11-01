#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isValid function below.
def isValid(s):
    s=list(s)
    sLen=len(s)
    sDict={}
    for i in range(sLen):
        if s[i] in sDict:
            sDict[s[i]]+=1
        else:
            sDict[s[i]]=1
    cntDict={}
    for letter in sDict:
        if sDict[letter] in cntDict:
            cntDict[sDict[letter]]+=1
        else:
            cntDict[sDict[letter]]=1 
    print(cntDict)
    if(len(cntDict)>2):
        return "NO"
    elif(len(cntDict)<2):
        return "YES"   
    else:
        prev=0
        for cnt in cntDict:
            if(prev<1):
                prev=cnt
            else:
                if (cntDict[cnt]<2 and cnt<2) or (cntDict[prev]<2 and prev<2):
                    return "YES"
                elif Abs(cnt-prev)>1 :
                    return "NO"
                elif cntDict[cnt]>1 and cntDict[prev]>1:
                    return "NO"
                else:
                    return "YES"    

def Abs(a):
    if a<0:
        return a*(-1)
    else:
        return a
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
