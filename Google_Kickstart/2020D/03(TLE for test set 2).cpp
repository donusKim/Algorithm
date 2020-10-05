#include <stdio.h>
int N;
int A;
int B;
int parent[505000];
int VisitCount_A[505000];
int VisitCount_B[505000];
int paint_temp[505000];
void Set_VisitCount(void);
int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d %d", &N, &A, &B);
		for (int j = 2; j < N + 1; j++) {
			scanf("%d", &parent[j]);
			VisitCount_A[j] = 0;
			VisitCount_B[j] = 0;
		}
		VisitCount_A[1] = 0;
		VisitCount_B[1] = 0;
		Set_VisitCount();
		double result=0.0;
		for (int j = 1; j < N + 1; j++) {
			result += 1.0-(1.0 - double(VisitCount_A[j]) / N)* (1.0 - double(VisitCount_B[j]) / N);
		}
		
		printf("Case #%d: %.6lf\n", i + 1, result);
	}

	return 0;
}
void Set_VisitCount(void) {
	int temp;
	int cnt;
	for (int i = 1; i < N + 1; i++) {
		cnt = 0;
		temp = i;
		while (temp != 0) {
			if (cnt % A == 0)
				VisitCount_A[temp]++;
			if (cnt % B == 0)
				VisitCount_B[temp]++;
			temp = parent[temp];
			cnt++;
		}
	}
}
