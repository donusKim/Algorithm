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
