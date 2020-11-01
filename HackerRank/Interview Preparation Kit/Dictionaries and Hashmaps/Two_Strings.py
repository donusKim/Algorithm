#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the twoStrings function below.
def twoStrings(s1, s2):
    s1=list(s1)
    s2=list(s2)
    hashmap={}
    for letter in s1:
        if(letter in hashmap):
            continue
        else:
            hashmap[letter]=1
    for letter in s2:
        if letter in hashmap:
            return "YES"
    return "NO"            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s1 = input()

        s2 = input()

        result = twoStrings(s1, s2)

        fptr.write(result + '\n')

    fptr.close()
