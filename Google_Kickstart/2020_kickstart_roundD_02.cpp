#include <stdio.h>
#define Big 10000000
#define ABS(x) ( ((x)<0)?-(x):(x) )
int arr[10100];
int highlow[10100];
int min;
int cum;
int K;
int len;
int main() {
	int tc;
	register int i, j;
	scanf("%d", &tc);
	for (i = 0; i < tc; i++) {
		scanf("%d", &K);
		len = 0;
		cum = 0;
		int high = 0;
		int low = 0;
		int temp_1;
		int temp_2;

		for (j = 0; j < K; j++) {
			scanf("%d", &arr[j]);
			if (j > 0) {
				if (arr[j] > arr[j - 1])
					high++;
				if (arr[j] < arr[j - 1])
					low++;
				if (high > 0 && low > 0) {
					if (high == 1 && arr[j] > arr[j - 1]) {
						highlow[len++] = low * (-1);
						low = 0;
					}
					if (low == 1 && arr[j] < arr[j - 1]) {
						highlow[len++] = high;
						high = 0;
					}
				}
			}
		}
		if (high > 0)
			highlow[len++] = high;
		if (low > 0)
			highlow[len++] = low * (-1);
		for (j = 0; j < len; j++) {
			temp_1 = ABS(highlow[j]);
			min += temp_1 / 4;

		}
		printf("Case #%d: %d\n", i + 1, min);
		min = 0;
	}
	return 0;
}
