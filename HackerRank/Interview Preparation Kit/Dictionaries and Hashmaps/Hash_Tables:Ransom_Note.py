#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
    mDict={}
    for word in magazine:
        if(word in mDict):
            mDict[word]+=1
        else:
            mDict[word]=1
    for word in note:
        if word not in mDict:
            print("No")
            return
        else:
            mDict[word]-=1
    for word in mDict:
        if(mDict[word]<0):
            print("No")
            return
    print("Yes")


if __name__ == '__main__':
    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = input().rstrip().split()

    note = input().rstrip().split()

    checkMagazine(magazine, note)
