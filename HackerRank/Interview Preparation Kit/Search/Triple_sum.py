#!/bin/python3

import math
import os
import random
import re
import sys

# arr에서 num보다 큰 첫 번째 수의 index 리턴
def bSearch(arr,num):
    arrLen=len(arr)
    l=0
    r=arrLen-1
    while(l<=r):
        mid=(int)(l+r)//2
        ## 찾으면 return 
        if(arr[mid]<=num and (mid==arrLen-1 or arr[mid+1]>num)):
            return mid+1
        if(arr[mid]>num):
            r=mid-1
        elif(arr[mid]<=num):
            l=mid+1    
    return 0
# Complete the triplets function below.
def triplets(a, b, c):
    a=list(set(a))
    b=set(b)
    c=list(set(c))
    # 이진탐색을 위해 정렬
    a.sort()
    c.sort()
    ans=0
    for numb in b:
        aCnt=bSearch(a,numb)
        cCnt=bSearch(c,numb)
        ans+=aCnt*cCnt
    return ans




if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    lenaLenbLenc = input().split()

    lena = int(lenaLenbLenc[0])

    lenb = int(lenaLenbLenc[1])

    lenc = int(lenaLenbLenc[2])

    arra = list(map(int, input().rstrip().split()))

    arrb = list(map(int, input().rstrip().split()))

    arrc = list(map(int, input().rstrip().split()))

    ans = triplets(arra, arrb, arrc)

    fptr.write(str(ans) + '\n')

    fptr.close()
