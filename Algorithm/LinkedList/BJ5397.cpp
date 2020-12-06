#include <stdio.h>
#include <stdlib.h>
#define maxLen 1010000 
struct node {
	char c;
	struct node* next;
	struct node* prev;
};
struct cursor {
	int count;
	struct node* point;
};
struct node arr[maxLen];
char log[maxLen];
int insert(char, struct cursor*,int);
void moveLeft(struct cursor*);
void moveRight(struct cursor*);
void erase(struct cursor*);
int main() {

	int T;
	int idx;
	int arrcnt;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		arrcnt = 0;
		struct node* head = &arr[arrcnt++];
		struct cursor* curr = (struct cursor*)malloc(sizeof(struct cursor));
		curr->count = 0;
		curr->point = head;
		head->next = NULL;
		head->prev = NULL;
		scanf("%s", log);
		idx = 0;
		while (log[idx] != '\0') {
			if (log[idx] == '<') {
				moveLeft(curr);
			}
			else if (log[idx] == '>') {
				moveRight(curr);
			}
			else if (log[idx] == '-') {
				erase(curr);
			}
			else {
				arrcnt=insert(log[idx], curr,arrcnt);
			}
			idx++;
		}
		while (head->next != NULL) {
			printf("%c", head->next->c);
			head = head->next;
		}
		printf("\n");
	}
	return 0;
}

int insert(char letter, struct cursor* curr,int idx) {
	curr->count += 1;
	struct node* newNode = &arr[idx++];
	newNode->c = letter;
	newNode->next = curr->point->next;
	if (curr->point->next != NULL)
		curr->point->next->prev = newNode;
	newNode->prev = curr->point;
	curr->point->next = newNode;
	curr->point = newNode;
	return idx;
}

void moveLeft(struct cursor* curr) {
	if (curr->point->prev == NULL)
		return;
	else
		curr->point = curr->point->prev;
}

void erase(struct cursor* curr) {
	if (curr->count < 1 || curr->point->prev==NULL)
		return;
	else {
		curr->point->prev->next = curr->point->next;
		if (curr->point->next != NULL)
			curr->point->next->prev = curr->point->prev;
		curr->count -= 1;
		curr->point = curr->point->prev;
	}
}
void moveRight(struct cursor* curr) {
	if (curr->point->next == NULL)
		return;
	else
		curr->point = curr->point->next;
}
