## Brute-Force

### 1. 평범한 배낭
- [문제링크](https://www.acmicpc.net/problem/12865)
- [풀이코드](https://github.com/donusKim/Algorithm/blob/master/baekjoon/DP/bj_12865.cpp)
- **문제요약**
> 배낭에 넣을 수 있는 무게가 정해져 있을 떄 물건의 가치의 합을 최대로 해서 배낭을 채우는 문제
- **메인로직** 
> 넣는 물건의 개수 만큼 step 을 밟아간다. 매 step마다 step번쨰 물건을 넣는것과 뺴는것을 비교해서 max값을 return한다.       
Memoization기법을 통해 step과 limit마다 최대값을 저장하여 나중에 해당 step, limit의 최대값을 호출할 떄 바로 memoization 배열서      
읽어서 return한다. --> 반복호출되는 시간을 절약
```cpp
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
```
### 2. 연속합
- [문제링크](https://www.acmicpc.net/problem/1912)
- [풀이코드](https://github.com/donusKim/Algorithm/blob/master/baekjoon/DP/bj_1912.cpp)
- **문제요약**
> n개의 정수로 이루어진 임의의 수열이 주어진다. 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하는 문제.
- **메인로직** 
> 가장 최근 수를 포함한 연속합중에 최대값인 max_continuos_sum을 업데이트 한다.      
> max_continuous_sum값 중 최대값이 답이다.
```cpp
for (int i=0;i<n;i++){
        max_continous_sum=MAX(max_continous_sum+arr[i],arr[i]);
        if (max_continous_sum>max_sum)
            max_sum=max_continous_sum;
    }
```

### 3. LCS(Longest Common Subsequenc)
- [문제링크](https://www.acmicpc.net/problem/9251)
- [풀이코드](https://github.com/donusKim/Algorithm/blob/master/baekjoon/DP/bj_9251.cpp)
- **문제요약**
> LCS(최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.    
> 예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.    
- **메인로직** 
> getLcs(char *arr1, char *arr2, int end1,int end2)함수는 첫번째 수열의 end1번쨰 까지와      
> 두번쨰 수열의 b번쨰 까지의 공통 부분 수열의 길이를 구하는 함수다.     
> memoization 배열에 저장하면서 반복호출 문제를 해결한다.
```cpp
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
```
