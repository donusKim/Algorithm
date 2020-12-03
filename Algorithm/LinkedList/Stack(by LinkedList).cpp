#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node* next;
};
void insert(int, struct Node*);
int pop(struct Node*);
int getCount(struct Node*);

int main() {
  struct Node* Head=(struct Node*)malloc(sizeof(struct Node));
  //확인용 코드
  insert(3,Head);
  insert(4,Head);
  insert(5,Head);
  printf("%d\n",pop(Head));
  printf("%d\n",getCount(Head)); 
  return 0;
}

void insert(int v, struct Node* head) {
	// 새로 Node 메모리 할당
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->next = head->next;
	newNode->value = v;
	head->next = newNode;
	// 개수 증가
	head->value += 1;
}

int pop(struct Node* head) {
	int cnt = head->value;
	if (cnt < 1) {
		return 0;
	}
	else {
		int temp = head->next->value;
		head->value -= 1;
		head->next = head->next->next;
		return temp;
	}
}

int getCount(struct Node* head) {
	return head->value;
}
