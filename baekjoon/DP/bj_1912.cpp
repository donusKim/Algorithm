#include <stdio.h>
#define MAX(x,y) ((x>y)?(x):(y))
#define maxN 101000
int arr[maxN];
int n;
int max_sum=(-1000)*maxN;
int max_continous_sum;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n;i++){
        max_continous_sum=MAX(max_continous_sum+arr[i],arr[i]);
        if (max_continous_sum>max_sum)
            max_sum=max_continous_sum;
    }
    printf("%d\n",max_sum);
    return 0;
}