import math
import os
import random
import re
import sys

def countTriplets(arr, r):
    """
    arr를 순회하면서 세가지 Dictionary를 채워넣는다.
    num_dict: arr 원소들의 개수를 count하는 Dict
    r_dict: r의 배수이면서 r로나눈 몫이 arr의 원소인 arr의 원소의 개수를 count하는 Dict
    rr_dict: r^2의 배수이면서 r로나눈 몫이 r_dict의 원소인 arr의 원소의 개수를 count하는 Dict
    """
    arr_len=len(arr)
    num_dict={}
    r_dict={}
    rr_dict={}
    ans=0
    for num in range(arr_len):
        if arr[num] in num_dict:
            num_dict[arr[num]]+=1
        else:
            num_dict[arr[num]]=1
            
        if arr[num]%r<1 and arr[num]//r in num_dict: 
            if arr[num] in r_dict:
                r_dict[arr[num]]+=num_dict[arr[num]//r]
            else:
                r_dict[arr[num]]=num_dict[arr[num]//r]
        if arr[num]%(r*r)<1 and arr[num]//r in r_dict:
            if arr[num] in rr_dict:
                rr_dict[arr[num]]+=r_dict[arr[num]//r]
            else:
                rr_dict[arr[num]]=r_dict[arr[num]//r]

    if r>1:
        for num in rr_dict:
            ans+=rr_dict[num]
            
    else:
        for num in num_dict:
            if(num_dict[num]>2):
                ans+=num_dict[num]*(num_dict[num]-1)*(num_dict[num]-2)//6

    return ans