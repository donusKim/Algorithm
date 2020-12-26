#include <stdio.h>
#define maxN 1000000
int getDigitSum(int num);
int getDigitNum(int num);
int max=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<getDigitNum(n)*9+1;i++){
        if(getDigitSum(n-i)==i)
            max=n-i;
    }
    printf("%d\n",max);
    return 0;
}

int getDigitNum(int num){
    int digitnum=0;
    while(num>0){
        digitnum+=1;
        num/=10;
}
    return digitnum;
}

int getDigitSum(int num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
}
    return sum;
}