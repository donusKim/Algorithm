#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the substrCount function below.
def substrCount(n, s):
    s=list(s)
    ans=n
    mid=-1
    ## 가운데는 다르고 대칭인 문자열 개수
    for i in range(n):
        mid=i
        step=1
        prev=0
        while(mid+step<n and mid-step>-1):
            if(step<2):
                if(s[mid+step]==s[mid-step] and s[mid-step]!=s[mid]):
                    ans+=1
                    prev=s[mid+step]
                    step+=1
                else:
                    break
            else:
                if(s[mid+step]!=prev or s[mid-step]!=prev ):
                    break
                else:
                    ans+=1
                    step+=1
    ## 같은문자열로만 이뤄진 개수,,
    consecutiveCntDict={}
    cnt=0
    prev=0
    for i in range(n):
        if(cnt<1):
            prev=s[i]
            cnt=1
        else:
            if prev==s[i]:
                cnt+=1
            else:
                if(cnt in consecutiveCntDict):
                    consecutiveCntDict[cnt]+=1
                else:
                    consecutiveCntDict[cnt]=1
                cnt=1
                prev=s[i]
    
    if(cnt>1):
        if(cnt in consecutiveCntDict):
            consecutiveCntDict[cnt]+=1
        else:
            consecutiveCntDict[cnt]=1
    
    for cnt in consecutiveCntDict:
        if(cnt>1):
            ans+=cnt*(cnt-1)//2*consecutiveCntDict[cnt]

    return ans



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = substrCount(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
