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
	//	int * A = (int *)malloc(sizeof(int) * N);       // ũ�� N��ŭ�� �迭 ����
		for (int j = 0; j < N; j++) {
			scanf("%d", A+j);							// ũ�� N�� �迭 A�� Ai �Է¹ޱ� &A[j]�� �Է¹����� ��������
		}
		quick_sort(A, 0, N - 1);						// �迭 A �������ϱ�
		int cnt = 0;
		int sum = 0;
		for (int k = 0; k < N; k++) {
			sum = sum + A[k];
			if (B >= sum)
				cnt++;
			else
				break;									// ���� B�� �Ѿ�� for�� ����������
		}
		printf("Case #%d: %d\n", i, cnt);
	//	free(A);
	}
	return 0;
}

void quick_sort(int arr[], int left,int right) {
	if (left < right) {
		int pivot = arr[left];  //  ���� ���� pivot ����
		int l = left + 1, r = right;	// pivot �ٷ� ������ left�� ���� �� ������ right ����
		while (r >= l) {               //right�� left���� ũ�ų� ���� �� ���� ���� 
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


// TLE ���� countingsort ������ �õ��غ���