## Dictionaries and Hashmaps

### 1. Count_Triplets
- [문제링크](https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps)
- [풀이코드](https://github.com/donusKim/Algorithm/blob/master/HackerRank/Interview%20Preparation%20Kit/Dictionaries%20and%20Hashmaps/Count_Triplets.py)
- **문제요약**
> 길이가 n인 배열 arr가 주어지고 공비 r이 주어졌을 때 배열내에서 공비 r인 등비수열을 이루는 3가지 숫자의 순서쌍의 개수를 구하는 문제
- **메인로직** 
> num_dict, r_dict, rr_dict를 업데이트 하는 로직 
```python
"""
    arr를 순회하면서 세가지 Dictionary를 채워넣는다.
    num_dict: arr 원소들의 개수를 count하는 Dict
    r_dict: r의 배수이면서 r로나눈 몫이 arr의 원소인 arr의 원소의 개수를 count하는 Dict
    rr_dict: r^2의 배수이면서 r로나눈 몫이 r_dict의 원소인 arr의 원소의 개수를 count하는 Dict
"""
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
```
> 업데이트된 Dict를 이용해 답을 구하는 로직
```python
"""
    r>1인 경우: rr_dict의 값들을 더한다
    r==1인 경우: num_dict의 값이 3이상일 때 nC3
"""
if r>1:
    for num in rr_dict:
        ans+=rr_dict[num]
            
else:
    for num in num_dict:
        if(num_dict[num]>2):
            ans+=num_dict[num]*(num_dict[num]-1)*(num_dict[num]-2)//6
```
