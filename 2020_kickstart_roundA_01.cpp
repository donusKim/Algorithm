#include <stdio.h>
#include <malloc.h>
int A[100000];
int main() {
	void quick_sort(int[], int, int);

	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		int N, B;
		scanf("%d %d", &N, &B);
	//	int * A = (int *)malloc(sizeof(int) * N);       // 크기 N만큼의 배열 생성
		for (int j = 0; j < N; j++) {
			scanf("%d", A+j);							// 크기 N인 배열 A에 Ai 입력받기 &A[j]로 입력받으면 오류생김
		}
		quick_sort(A, 0, N - 1);						// 배열 A 퀵정렬하기
		int cnt = 0;
		int sum = 0;
		for (int k = 0; k < N; k++) {
			sum = sum + A[k];
			if (B >= sum)
				cnt++;
			else
				break;									// 예산 B를 넘어가면 for문 빠져나가기
		}
		printf("Case #%d: %d\n", i, cnt);
	//	free(A);
	}
	return 0;
}

void quick_sort(int arr[], int left,int right) {
	if (left < right) {
		int pivot = arr[left];  //  가장 왼쪽 pivot 설정
		int l = left + 1, r = right;	// pivot 바로 오른쪽 left로 설정 맨 오른쪽 right 설정
		while (r >= l) {               //right가 left보다 크거나 같을 때 까지 진행 
			while (arr[l] <= pivot) {
				l++;
			}
			while (arr[r] > pivot) {
				r--;
			}
			if (r >l) {
				int temp = arr[l];
				arr[l] = arr[r];
				arr[r] = temp;
				r--;
				l++;
			}
		}
		int tem;
		arr[left] = arr[r];
		arr[r] = pivot;
		quick_sort(arr,left, r - 1);
		quick_sort(arr, r + 1, right);
	}
}


// TLE 나서 countingsort 버전을 시도해본다
