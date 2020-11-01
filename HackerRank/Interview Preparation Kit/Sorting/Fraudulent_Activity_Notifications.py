#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the activityNotifications function below.
def activityNotifications(expenditure, d):
    ans=0
    eLen=len(expenditure)
    ## counting sort 에 활용될 배열
    cntArr=[0 for x in range(201)]
    for i in range(d):
        cntArr[expenditure[i]]+=1
    if d%2>0:
        cnt=0
        mid=0
        curr=d
        # 처음 median을 구한다
        for i in range(201):
            cnt+=cntArr[i]
            if cnt >= d//2+1:
                mid=i
                break
        if mid*2<=expenditure[curr]:
            ans+=1
        while curr<eLen-1:
            cntArr[expenditure[curr]]+=1
            cntArr[expenditure[curr-d]]-=1
            cnt=0
            for i in range(201):
                cnt+=cntArr[i]
                if cnt >= d//2+1:
                    mid=i
                    break
            curr+=1
            if mid*2<=expenditure[curr]:
                ans+=1

    else:
        cnt=0
        mid=0
        curr=d
        # 처음 median을 구한다
        for i in range(201):
            cnt+=cntArr[i]
            if cnt == d//2:
                mid1=i
                mid2=i+1
                while cntArr[mid2]<1:
                    mid2+=1
                mid=mid1+mid2
                break
            elif cnt>d//2:
                mid=i*2
                break
        if mid<=expenditure[curr]:
            ans+=1
        while curr<eLen-1:
            cntArr[expenditure[curr]]+=1
            cntArr[expenditure[curr-d]]-=1
            cnt=0
            for i in range(201):
                cnt+=cntArr[i]
                if cnt == d//2:
                    mid1=i
                    mid2=i+1
                    while cntArr[mid2]<1:
                        mid2+=1
                    mid=mid1+mid2
                    break
                elif cnt>d//2:
                    mid=i*2
                    break
            curr+=1
            if mid<=expenditure[curr]:
                ans+=1
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    expenditure = list(map(int, input().rstrip().split()))

    result = activityNotifications(expenditure, d)

    fptr.write(str(result) + '\n')

    fptr.close()
