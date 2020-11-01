#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the commonChild function below.
def commonChild(s1, s2):
    lenS=len(s1)
    dp=[[0 for x in range(lenS+1)] for x in range(lenS+1)]
    for i in range (1,lenS+1):
        for j in range (1,lenS+1):
            if s1[i-1]==s2[j-1]:
                dp[i][j]=dp[i-1][j-1]+1
            else:
                dp[i][j]=Max(dp[i-1][j],dp[i][j-1])
    return dp[lenS][lenS]


def Max(a , b):
    if a>b:
        return a
    else:
        return b


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s1 = input()

    s2 = input()

    result = commonChild(s1, s2)

    fptr.write(str(result) + '\n')

    fptr.close()
