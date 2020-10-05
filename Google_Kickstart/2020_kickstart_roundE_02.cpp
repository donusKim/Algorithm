#include <stdio.h>
int N;
int A;
int B;
int C;
void sol(void);
int main() {
	int tc;
	scanf("%d", &tc);
	register int i;
	for (i = 0; i < tc; i++) {
		scanf("%d %d %d %d", &N, &A, &B, &C);
		printf("Case #%d: ", i + 1);
		sol();
		printf("\n");
	}
	return 0;
}
void sol(void) {
	if (C > A || C > B || A + B - C > N || (N>1 && A-C ==0 && B-C==0 && C==1)) {
		printf("IMPOSSIBLE");
		return;
	}
	else {
		int left = A - C;
		int right = B - C;
		int resid = N - (A + B - C);
		// no resid
		if (resid < 1) {
			if (left > 0) {
				for (int i = N - left; i < N; i++) {
					printf("%d ", i);
				}
			}
			for (int i = 0; i < C; i++) {
				printf("%d ", N);
			}
			if (right > 0) {
				for (int i = N - 1; i > N - 1 - right; i--) {
					printf("%d ", i);
				}
			}
		}
		// resid>0
		if (resid > 0) {
			if (right > 0) {
				if (left > 0) {
					for (int i = N - left; i < N; i++) {
						printf("%d ", i);
					}
				}
				for (int i = 0; i < C; i++) {
					printf("%d ", N);
				}
				for (int i = 0; i < resid; i++) {
					printf("%d ", 1);
				}
				if (right > 0) {
					for (int i = N - 1; i > N - 1 - right; i--) {
						printf("%d ", i);
					}
				}
			}
			else if(left>0){
				if (left > 0) {
					for (int i = N - left; i < N; i++) {
						printf("%d ", i);
					}
				}
				for (int i = 0; i < resid; i++) {
					printf("%d ", 1);
				}
				for (int i = 0; i < C; i++) {
					printf("%d ", N);
				}
				if (right > 0) {
					for (int i = N - 1; i > N - 1 - right; i--) {
						printf("%d ", i);
					}
				}
			}
			else {
				if (left > 0) {
					for (int i = N - left; i < N; i++) {
						printf("%d ", i);
					}
				}
				printf("%d ", N);
				for (int i = 0; i < resid; i++) {
					printf("%d ", 1);
				}
				for (int i = 1; i < C; i++) {
					printf("%d ", N);
				}
				if (right > 0) {
					for (int i = N - 1; i > N - 1 - right; i--) {
						printf("%d ", i);
					}
				}
			}
		}
	}
}
