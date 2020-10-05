#include <stdio.h>
#define MaxN 200001
int array[MaxN];
int N, K;
int cnt;
int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
	   
		scanf("%d %d", &N, &K);
		cnt = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &array[j]);
		}
		for (int j = 0; j < N; j++) {
		    if (j + K > N )
			    break;
			if (array[j] == K) {
				for (int k = j + 1; k < j + K; k++) {
					if (array[k] != K - k + j)
						break;
					if (k == K + j - 1)
						cnt++;
				}
			j += K-1;    
			}
			
		}
		printf("Case #%d: %d\n", i + 1, cnt);
	}
	return 0;
}
