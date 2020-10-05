#include <stdio.h>
#define maxN 101000
typedef struct Node{
	int enjoy;
	int remember;
	struct Node* next;
	struct Node* prev;
}Node;
Node linkedList[maxN];
Node head;
Node temp;
Node* h1;
Node* h2;
Node* deleteIdx;
void insertNode(Node*, Node*);
void deleteNode(Node* target);
int N;
long long totalEnjoy;
long long max;
int maxstep;
void sol(int);
int main() {
	int tc;
	scanf("%d", &tc);
	register int i, j;
	for (i = 0; i < tc; i++) {
		totalEnjoy = 0;
		max = 0;
		maxstep = 0;
		scanf("%d", &N);
		int e, r;
		for (j = 0; j < N; j++) {
			scanf("%d %d", &e, &r);
			totalEnjoy += e;
			linkedList[j].enjoy = e;
			linkedList[j].remember = r;
			insertNode(&head, &linkedList[j]);
		}
		//totalEnjoy-enjoy[j]<remember[j]면 울고 끝난다..
		printf("Case #%d: ", i + 1);
		sol(0);
		printf("\n");
		head = temp;
	}
	return 0;
}

// 시뮬레이션 돌리는 함수..두가지를 print 해야됨,,빼는 개수와 최대값 혹은 infinite여부
void sol(int step) {

	if (step == N) {
		printf("%d %lld", maxstep, max);
		return;
	}
	int eraseCnt = 0;
	int eraseidx = 0;
	long long cusum = 0;
	h1 = &head;
	Node* deleteIdx;
	h1 = h1->next;
	// 빼줘야 하는 노드 발견할 때 까지 while문 진행
	while (totalEnjoy - h1->enjoy >= h1->remember) {
		if (h1->next == NULL)
			break;
		h1 = h1->next;
	}
	if (h1->next != NULL || (h1->next == NULL && totalEnjoy - h1->enjoy < h1->remember)) {
		eraseCnt++;
		deleteIdx = h1;
		h2 = &head;
		cusum = totalEnjoy;
		while (h2->next != deleteIdx) {
			cusum += h2->next->enjoy;
			h2 = h2->next;
		}
		if (cusum > max) {
			max = cusum;
			maxstep = step;
		}
		totalEnjoy = totalEnjoy - deleteIdx->enjoy;
		deleteNode(deleteIdx);
	}
	// 지워야할것이 없을때,,,무한루프를 돌떄!
	if (eraseCnt < 1) {
		printf("%d INDEFINITELY", step);
		return;
	}
	sol(step + 1);
}
void insertNode(Node* head, Node* target) {
	while (head->next != NULL) {
		head = head->next;
	}
	target->next = head->next;
	head->next = target;
	target->prev = head;
	return;
}

void deleteNode(Node* target) {
	if (target->next != NULL) {
		target->prev->next = target->next;
		target->next->prev = target->prev;
	}
	else 
		target->prev->next = target->next;
}
