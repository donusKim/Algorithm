#include <stdio.h>

int arr[303000];
int max = 0;
int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		scanf(" %d", &arr[i]);
	}
	for (int i = 0; i < M - 2; i++) {
		for (int j = i+1; j < M - 1; j++) {
			for (int k = j + 1; k < M ; k++) {
				if (arr[i] + arr[j] + arr[k] > max && arr[i] + arr[j] + arr[k] < N + 1)
					max = arr[i] + arr[j] + arr[k];
			}
		}
	}
	printf("%d\n", max);
	return 0;
}