#include <stdio.h>
#define MAX(x,y) ((x>y)?(x):(y))
#define maxN 110
#define maxK 101000

int weights[maxN];
int values[maxN];
int visited[maxN];
int getMaxValues(int , int );
int n,k;
int max_sum;
int memoization[maxN][maxK];
int main(){
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d %d",&weights[i],&values[i]);
    }    
    printf("%d\n",getMaxValues(0,k));
    return 0;
}

int  getMaxValues(int step, int limit){
    if (memoization[step][limit]>0)
        return memoization[step][limit];
    if (limit<1 || step>n-1)
        return 0;
    if (limit>=weights[step]){
        memoization[step][limit]=MAX(getMaxValues(step+1,limit-weights[step])+values[step],getMaxValues(step+1, limit));
    }    
    else{
        memoization[step][limit]=getMaxValues(step+1, limit);
    }
    return memoization[step][limit];
}