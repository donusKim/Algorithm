#include <stdio.h>
#define maxN 202000
int N;
int arr[maxN];
int diff[maxN];
int sol(void);
int main() {
	int tc;
	register int i, j;
	scanf("%d", &tc);
	for (i = 0; i < tc; i++) {
		int ans;
		scanf("%d", &N);
		for (j = 0; j < N; j++) {
			scanf(" %d", &arr[j]);
			if (j > 0)
				diff[j - 1] = arr[j] - arr[j - 1];
		}
		ans = sol()+1;
		printf("Case #%d: %d\n", i + 1, ans);
	}

	return 0;
}

int sol(void) {
	int consecutiveCount = 1;
	int max = 1;
	for (int k = 1; k < N - 1; k++) {
		if (diff[k] == diff[k - 1])
			consecutiveCount++;
		else
			consecutiveCount = 1;
		if (consecutiveCount > max)
			max = consecutiveCount;
	}
	return max;
}
