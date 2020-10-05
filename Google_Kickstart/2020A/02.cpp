#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

int beauty_value[51][31];
int dpmatrix[51][1501];
int sum[51][31];
int N, K, P;
int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		scanf("%d %d %d", &N, &K, &P);
		for (int j = 1; j <= N; j++)  for (int k = 1; k <= K; k++) scanf("%d", &beauty_value[j][k]);   // beauty value 입력받기
		for (int j = 1; j <= N; j++) {
			int s = 0;
			for (int k = 1; k <= K; k++) {
				s = s + beauty_value[j][k];
				sum[j][k] = s;								// sum값 업데이트
			}
		}

		for (int m = 1; m <= N; m++) {
			for (int n = 1; n <= P; n++) {
				dpmatrix[m][n] = 0;
				for (int i = 0; i <= min(n, K); i++) {
					if (dpmatrix[m][n] < dpmatrix[m - 1][n - i] + sum[m][i])
						dpmatrix[m][n] = dpmatrix[m - 1][n - i] + sum[m][i];
				}
			}
		}

		printf("Case #%d: %d\n", i, dpmatrix[N][P]);
	}
	return 0;
}
