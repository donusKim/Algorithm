#!/bin/python3

import os
import sys

sys.setrecursionlimit(2000)
# Complete the swapNodes function below.
#
class treeNode(object):
    def __init__(self,v,left=None,right=None):
        self.value=v
        self.left=left
        self.right=right
        self.depth=0    

def convert(a,arr):
    if(a<0):
        return None
    else:
        return arr[a]   
    
def makeDepth(root,depth):
    root.depth=depth
    if(root.left):
        makeDepth(root.left,depth+1)
    if(root.right):
        makeDepth(root.right,depth+1)
            
def traverse(node,l):
    if(node.left):
        traverse(node.left,l)
    l.append(node.value)
    if(node.right):
        traverse(node.right,l)   


def swapNodes(indexes, queries):
    n=len(indexes)
    ## 모든 node 저장한 list,,,편의상 앞에는 0
    nodelist=[0 for x in range(n+1)]
    ## 뒤에서 부터 생성
    for i in range(n):
        nodelist[n-i]=treeNode(n-i,convert(indexes[n-1-i][0],nodelist),convert(indexes[n-1-i][1],nodelist))
    makeDepth(nodelist[1],1)
    queryLen=len(queries)
    ans=[]
    for i in range(queryLen):
        k=queries[i]
        for i in range(1,n+1):
            ## depth가 k면 left와 right 바꿔준다
            if(nodelist[i].depth%k==0):
                
                temp=nodelist[i].left
                nodelist[i].left=nodelist[i].right
                nodelist[i].right=temp
        ## 이제 순회 code
        traverseList=[]
        traverse(nodelist[1],traverseList)
        ans.append(traverseList)
    return ans
                


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    indexes = []

    for _ in range(n):
        indexes.append(list(map(int, input().rstrip().split())))

    queries_count = int(input())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input())
        queries.append(queries_item)

    result = swapNodes(indexes, queries)

    fptr.write('\n'.join([' '.join(map(str, x)) for x in result]))
    fptr.write('\n')

    fptr.close()
