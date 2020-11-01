#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sherlockAndAnagrams function below.
def sherlockAndAnagrams(s):
    s=list(s)
    lenS=len(s)
    sum=0
    for length in range(1,lenS):
        sDict={}
        for start in range(0,lenS-length+1):
            if convert(s[start:start+length]) in sDict:
                sDict[convert(s[start:start+length])]+=1
            else:
                sDict[convert(s[start:start+length])]=1
        for hashed in sDict:
            sum+=sDict[hashed]*(sDict[hashed]-1)//2
    
    return sum


def convert(s):
    s.sort()
    l=""
    for i in range(len(s)):
         l+=s[i]
    return l
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = sherlockAndAnagrams(s)

        fptr.write(str(result) + '\n')

    fptr.close()
