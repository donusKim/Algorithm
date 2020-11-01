#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maximumSum function below.
def maximumSum(a, m):
    aLen=len(a)
    Max=0
    cusum=[[] for x in range(aLen)]
    cusum[0].append(a[0]%m)
    cusum[0].append(0)
    if a[0]%m>Max:
        Max=a[0]%m
    # 인덱스와 누적 나머지 합을 모두 넣어준다
    for i in range(1,aLen):
        cusum[i].append((cusum[i-1][0]+a[i])%m)
        cusum[i].append(i)
        if cusum[i][0]>Max:
            Max=cusum[i][0]
    ## 누적 나머지 합 기준으로 정렬
    cusum.sort()
    Min=m
    for i in range(1,aLen):
        if cusum[i][1]<cusum[i-1][1] and cusum[i][0]>cusum[i-1][0] and cusum[i][0]-cusum[i-1][0]<Min:
            Min=cusum[i][0]-cusum[i-1][0]
    if m-Min>Max:
        Max=m-Min
    
    return Max

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        nm = input().split()

        n = int(nm[0])

        m = int(nm[1])

        a = list(map(int, input().rstrip().split()))

        result = maximumSum(a, m)

        fptr.write(str(result) + '\n')

    fptr.close()
