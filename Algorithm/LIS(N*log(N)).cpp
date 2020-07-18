#include <stdio.h>
int N;
int A[1100000]; 
int Min_right[1100000];      // Min_right[i]는 길이가 i인 부분수열의 오른쪽 끝 값이 될 수 있는 값중 가장 작은값
int max = 0;
int l;
int r;
int mid;
int main() {
	scanf("%d", &N);
	register int i;
	for (i = 0; i < N; i++) {
		scanf(" %d", &A[i]);
		l = 1;
		r = max;
		if (i == 0) {
			Min_right[++max] = A[i];
		}
		else {
			// Min_right[max]보다 클때
			if (Min_right[max] < A[i])
				Min_right[++max] = A[i];
			// Min_right[1]보다 작을때
			else if(Min_right[1]>=A[i])
				Min_right[1] = A[i];
			else {
				while (l<=r) {
					mid = (l + r) / 2;
					if (Min_right[mid] >= A[i]) {
						if (Min_right[mid - 1] < A[i])
							break;
						else {
							r = mid-1;
						}
					}
					if (Min_right[mid] < A[i]) {
						l = mid + 1;
					}
				}
				Min_right[mid] = A[i];
			}
		}
	}
	printf("%d", max);
	return 0;
}
