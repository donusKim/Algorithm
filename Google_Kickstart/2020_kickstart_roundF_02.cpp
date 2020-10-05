#include <stdio.h>
#define maxN 101000
int N;
int K;
typedef struct {
	int s;
	int e;
}Heap;
Heap h[maxN];
int heapcnt;
void initHeap(void);
void insert(int , int );
Heap pop(void);
int main() {
	int tc;
	int a;
	int b;
	int interval;
	int add;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int ans = 0;
		int curr = 0;
		scanf("%d %d", &N, &K);
		//최소힙에 s기준으로 넣어버림
		for (int j = 0; j < N; j++) {
			scanf("%d %d", &a, &b);
			insert(a, b);
		}
		// 이제 하나씩 꺼낸다
		for (int j = 0; j < N; j++) {
			Heap x = pop();
			// 지금영향을 충분히끼칠경우 continue
			if (curr >= x.e)
				continue;
			else if (curr > x.s) {
				interval = x.e - curr;
				add = interval % K < 1 ? interval / K : interval / K + 1;
				ans += add;
				curr += add * K;
			}
			else {
				interval = x.e - x.s;
				add = interval % K < 1 ? interval / K : interval / K + 1;
				ans += add;
				curr = x.s + add * K;
			}			
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
	
	return 0;
}

void initHeap(void) {
	heapcnt = 0;
}

void insert(int s, int e) {
	//먼저 끝에 놓는다
	h[heapcnt].s = s;
	h[heapcnt++].e = e;
	//이제부모노드와 비교,,최소힙을 만들 계획,,
	int child = heapcnt-1;
	int parent = (child - 1) / 2;
	while (h[parent].s > h[child].s && child>0) {
		Heap temp;
		temp = h[child];
		h[child] = h[parent];
		h[parent]= temp;
		child = parent;
		parent= (child - 1) / 2;
	}
	return;
}

Heap pop(void) {
	Heap p = h[0];
	// 제일끝에꺼 위로 올리기
	h[0] = h[--heapcnt];
	int parent = 0;
	int child;
	if (2 * parent + 1 > heapcnt - 1)
		return p;
	else if (2 * parent + 2 > heapcnt - 1)
		child = 2 * parent + 1;
	else 
		child = h[2 * parent + 1].s > h[2 * parent + 2].s ? 2 * parent + 2 : 2 * parent + 1;
	while (h[parent].s > h[child].s) {
		Heap temp;
		temp = h[child];
		h[child] = h[parent];
		h[parent] = temp;
		parent = child;
		if (2 * parent + 1 > heapcnt - 1)
			return p;
		else if (2 * parent + 2 > heapcnt - 1)
			child = 2 * parent + 1;
		else
			child = h[2 * parent + 1].s > h[2 * parent + 2].s ? 2 * parent + 2 : 2 * parent + 1;
	}
	return p;
}
