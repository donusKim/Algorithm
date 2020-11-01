#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minTime function below.
def minTime(machines, goal):
    n=len(machines)
    l=1
    r=1000000000000000000
    while(l<=r):
        mid=(int)(l+r)//2
        prod=getProduction(n,machines,mid)
        if(prod>=goal and (mid<2 or getProduction(n,machines,mid-1)<goal)):
            return mid
        if(prod<goal):
            l=mid+1
        else:
            r=mid-1

            

def getProduction(num,machines,day):
    total=0
    for i in range(num):
        total+=day//machines[i]
    return total



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nGoal = input().split()

    n = int(nGoal[0])

    goal = int(nGoal[1])

    machines = list(map(int, input().rstrip().split()))

    ans = minTime(machines, goal)

    fptr.write(str(ans) + '\n')

    fptr.close()
