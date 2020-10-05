#include <stdio.h>
#define MaxN 100000
int M[MaxN];
int D[MaxN - 1];
int N, K;
int main() {
	int bisection(void);
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &N, &K);
		for (int j = 0; j < N; j++) {
			scanf("%d", &M[j]);
			if (j > 0)
				D[j - 1] = M[j] - M[j - 1];
		}
		int answer = bisection();
		printf("Case #%d: %d\n", i + 1, answer);
	}


}

int bisection(void) {
	int divide_ceiling(int, int);
	int ksum = 0;
	int low = 1, high = M[N - 1];
	int d_optimal = 0;
	while (low + 1 < high) {
		d_optimal = (low + high) / 2;
		ksum = 0;
		for (int i = 0; i < N - 1; i++) {
			ksum += divide_ceiling(D[i], d_optimal) - 1;
		}
		if (ksum <= K)
			high = d_optimal;
		else
			low = d_optimal;
	}
	int ksum_low = 0;
	for (int i = 0; i < N - 1; i++) {
		ksum_low += divide_ceiling(D[i], low) - 1;
	}
	if (ksum_low <= K) {
		return low;
	}
	else {
		return high;
	}
}


int divide_ceiling(int a, int b) {
	if (a % b == 0)
		return a / b;
	else {
		return a / b + 1;
	}
