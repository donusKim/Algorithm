#include <stdio.h>
#include <malloc.h>
int A[100000];
// Ai는 1부터 1000까지만 가능하기때문에 그에비해 N은 100000개까지 가능하기 때문에 counting sort 시도 O(N)이다

int main() {
	void quick_sort(int[], int, int);
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		int N, B;
		int countA[1000] = {0};
		scanf("%d %d", &N, &B);
		//	int * A = (int *)malloc(sizeof(int) * N);       // 크기 N만큼의 배열 생성
		for (int j = 0; j < N; j++) {
			scanf("%d", A + j);							// 크기 N인 배열 A에 Ai 입력받기 &A[j]로 입력받으면 오류생김
		}
		for (int l = 0; l < N; l++) {
			countA[A[l] - 1]++;                       // O(N)으로 countA행렬 완성
		}
		int cnt = 0;
		int sum = 0;
		for (int k = 0; k < 1000; k++) {
			if (sum > B)	break;
			while (countA[k] > 0) {
				sum = sum + k + 1;
				countA[k]--;
				if (sum <= B)	cnt++;
				else   
					break;
			}
	
		}
		printf("Case #%d: %d\n", i, cnt);
	}
	return 0;
}
