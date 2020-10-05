#include <stdio.h>
int N;
int cnt;
int visiter[200200];
int max_prev[200200];
int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &visiter[j]);
			if (j == 0)
				max_prev[j] = visiter[j];
			else {
				if (max_prev[j - 1] > visiter[j])
					max_prev[j] = max_prev[j - 1];
				else
					max_prev[j] = visiter[j];
			}
		}
		for (int j = 0; j < N; j++) {
			if (!(j == 0 || visiter[j] > max_prev[j - 1]))
				continue;
			if (j == N - 1 || visiter[j] > visiter[j + 1])
				cnt++;
		}
		printf("Case #%d: %d\n", i + 1, cnt);
		cnt = 0;

	}
	return 0;
}
