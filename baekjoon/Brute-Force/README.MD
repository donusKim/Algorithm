## Brute-Force

### 1. 블랙잭
- [문제링크](https://www.acmicpc.net/problem/2798)
- [풀이코드](https://github.com/donusKim/Algorithm/blob/master/baekjoon/Brute-Force/bj_2798.cpp)
- **문제요약**
> 카드가 여러개 주어지고 숫자 N에 가장 세 카드의 합을 구하는 문제
- **메인로직** 
> for문 세번 돌려서, N보다 크지 않으면서 이전 max값보다 크면 max를 업데이트 한다.
```cpp
for (int i = 0; i < M - 2; i++) {
		for (int j = i+1; j < M - 1; j++) {
			for (int k = j + 1; k < M ; k++) {
				if (arr[i] + arr[j] + arr[k] > max && arr[i] + arr[j] + arr[k] < N + 1)
					max = arr[i] + arr[j] + arr[k];
			}
		}
	}
```
### 2. 분해합
- [문제링크](https://www.acmicpc.net/problem/2231)
- [풀이코드](https://github.com/donusKim/Algorithm/blob/master/baekjoon/Brute-Force/bj_2231.cpp)
- **문제요약**
> 합을 만들어야 하는 숫자 N이 주어진다. 자리수 합과 자기자신을 더했을 때 N이되는 가장 작은 생성자 M을 구하는 문제
- **메인로직**
> N의 자리수를 구한 후 9를 곱하면 자리수 합의 범위를 정할 수 있다. 자리수 합 범위를 for문으로 돌면서 자리수 합과 자기자신을 더했을 때 N이되는 최솟값을 구한다.
```cpp
for(int i=1;i<getDigitNum(n)*9+1;i++){
        if(getDigitSum(n-i)==i)
            max=n-i;
    }
```
