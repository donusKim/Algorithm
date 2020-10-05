# include <stdio.h>
#include <stdbool.h>
# define MaxN 100
int H[MaxN+1];
int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int N;
		scanf("%d", &N);
		int peak_num = 0;
		for (int j = 1; j <= N; j++) {
			scanf("%d", &H[j]);
			bool peak = false;
			if (j > 2 && j <=N) {
				peak =(H[j - 1] > H[j]) && (H[j - 1] > H[j - 2]);
			}
			if (peak)
				peak_num++;
		}
		printf("Case #%d: %d\n",i+1,peak_num);
	}
	return 0;
}
