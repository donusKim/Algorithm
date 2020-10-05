#include <stdio.h>
#define maxN 101000
int N;
int X;
typedef struct {
	int num;
	int money;
	int cnt;
}info;
info queue[maxN];
info temp[maxN];
void mergeSort(int , int );
int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &N, &X);
		for (int j = 0; j < N; j++) {
			scanf("%d", &queue[j].money);
			queue[j].num = j + 1;
			if (queue[j].money%X == 0)
				queue[j].cnt = queue[j].money / X;
			else
				queue[j].cnt = queue[j].money / X+1;
		}
		// 정렬한다
		mergeSort(0,N-1);
		printf("Case #%d: ", i + 1);
		for (int j = 0; j < N; j++) {
			printf("%d ", queue[j].num);
		}
		printf("\n");
	}
	return 0;
}

void mergeSort(int l,int r) {
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	mergeSort(l, mid);
	mergeSort(mid+1, r);
	int left = l;
	int right = mid + 1;
	int front = 0;
	while (left < mid + 1 && right < r + 1) {
		if (queue[left].cnt > queue[right].cnt) temp[front++] = queue[right++];
		
		else if (queue[left].cnt < queue[right].cnt) temp[front++] = queue[left++];
		else {
			if (queue[left].num < queue[right].num) temp[front++] = queue[left++];
			else temp[front++] = queue[right++];
		}
	}
	while (right < r + 1) temp[front++] = queue[right++];
	while (left < mid + 1) temp[front++] = queue[left++];
	for (int i = 0; i < r - l + 1; i++) {
		queue[l + i] = temp[i];
	}
}
