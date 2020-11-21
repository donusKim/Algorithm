# BIT (Binary Indexed Tree)
```
C++
#include <stdio.h>
#define maxN 50500
int N;
int Q;
int arr[maxN];
int Aarr[maxN];
int sIdx;
int eIdx;
void insert(int idx, int value);
int getSum(int idx);
int main() {
	scanf("%d %d", &N, &Q);
	// 배열 값 입력받기
	for (int i = 1; i < N+1; i++) {
		scanf("%d", &arr[i]);
		insert(i, arr[i]);
	}

	// Query값 입력받고 답 구해서 출력
	for (int j = 0; j < Q; j++) {
		scanf("%d %d", &sIdx, &eIdx);
		printf("%d\n", getSum(eIdx) - getSum(sIdx-1));
	}
	return 0;
}

void insert(int idx, int value) {
	int x = idx;
	while (x < N + 1) {
		Aarr[x] += value;
		x += x & (-x);
	}
}

int getSum(int idx) {
	int x = idx;
	int sum = 0;
	while (x > 0) {
		sum += Aarr[x];
		x -= x & (-x);
	}
	return sum;
} 
```
