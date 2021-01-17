#include <stdio.h>
#define max_len 1010
int memoization[max_len][max_len];
int getLcs(char *, char *,int ,int );
int get_len(char *);
int main(){
    int len1;
    int len2;
    char arr1[max_len];
    char arr2[max_len];
    scanf("%s",arr1);
    scanf("%s",arr2);
    len1=get_len(arr1);
    len2=get_len(arr2);
    printf("%d\n", getLcs(arr1, arr2, len1-1,len2-1));
    return 0;
}

int getLcs(char *arr1, char *arr2, int end1,int end2){
    char pivot;
    int len;
    int max=0;
    int idx;
    if(end1<0 || end2<0)
        return 0;
    if(memoization[end1][end2]>0)
        return memoization[end1][end2];
    for(int i=end2;i>-1;i--){
        len=0;
        pivot=arr2[i];
        idx=-1;
        for(int j=end1;j>-1;j--){
            if(arr1[j]==pivot){
                idx=j;
                break;
            }
        }
        if(idx>=0)
            len=1+getLcs(arr1, arr2, idx-1, i-1);
        if(len>max)
            max=len;
    }
    memoization[end1][end2]=max;
    return max;
}

int get_len(char *x){
    int len=0;
    while(x[len]!='\0'){
        len++;
    }
    return len;
}