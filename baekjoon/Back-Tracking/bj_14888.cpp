#include <stdio.h>
#define maxN 13
#define INF 1000000000
int arrLen;
int arr[maxN];
int operationCnt[4];
long long min = INF;
long long max=(-1)*INF;
void dfs(int, long long, int, int, int, int);
long long divide(long long, int);
int main() {
	scanf("%d", &arrLen);
	for (int i = 0; i < arrLen; i++) {
		scanf(" %d", &arr[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf(" %d", &operationCnt[i]);
	}
	dfs(0, arr[0], operationCnt[0], operationCnt[1], operationCnt[2], operationCnt[3]);
	printf("%lld\n", max);
	printf("%lld\n", min);
	return 0;
}

void dfs(int step, long long cusum, int plus, int minus, int mul, int div) {
    if (step == arrLen - 1) {
		if (cusum > max)
			max = cusum;
		if (min > cusum)
			min = cusum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			if (plus > 0)
				dfs(step + 1, cusum + arr[step + 1], plus - 1, minus, mul, div);
			else continue;
		}
		else if (i == 1) {
			if (minus > 0)
				dfs(step + 1, cusum - arr[step + 1], plus, minus - 1, mul, div);
			else continue;
		}
		else if (i == 2) {
			if (mul > 0)
				dfs(step + 1, cusum*arr[step + 1], plus, minus, mul - 1, div);
			else continue;
		}
		else {
			if (div > 0)
				dfs(step + 1, divide(cusum, arr[step + 1]), plus, minus, mul, div - 1);
			else continue;
		}
	}
	return;
}

long long divide(long long a, int b) {
	if (a < 0)
		return (((-1)*a) / b)*(-1);
	else
		return a / b;
}