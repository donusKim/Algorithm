#include <stdio.h>
#define MaxN 1000
long long X[MaxN + 1];
int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int N;
		long long D, a;
		scanf("%d %lld ", &N, &D);
		for (int j = 1; j <= N; j++) {
			scanf("%lld", &X[j]);
		}
		for (int k = N; k >= 1; k--) {
			a = (D / X[k]);
			D = a * X[k];
		}
		printf("Case #%d: %lld\n", i + 1, D);
	}	return 0;
}
