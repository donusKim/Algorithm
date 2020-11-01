#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the alternatingCharacters function below.
def alternatingCharacters(s):
    s=list(s)
    sLen=len(s)
    ans=0
    currentIdx=0
    compareIdx=1
    while(compareIdx<sLen):
        if(s[currentIdx]==s[compareIdx]):
            ans+=1
            compareIdx+=1
        else:
            currentIdx=compareIdx
            compareIdx+=1
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = alternatingCharacters(s)

        fptr.write(str(result) + '\n')

    fptr.close()
