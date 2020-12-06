## 연결리스트(LinkedList)를 활용한 스택구현
### [Code](https://github.com/donusKim/Algorithm/blob/master/Algorithm/LinkedList/Stack(by%20LinkedList).cpp)

- Insert
```cpp
void insert(int v, struct Node* head) {
	// 새로 Node 메모리 할당
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->next = head->next;
	newNode->value = v;
	head->next = newNode;
	// 개수 증가
	head->value += 1;
}
```

- Pop
```cpp
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
```

- getCount
```cpp
int getCount(struct Node* head) {
	return head->value;
}
```

## 연결리스트(LinkedList)를 활용한 예제 : 키로거 문제
### [문제](https://www.acmicpc.net/problem/5397)
### [Code](https://github.com/donusKim/Algorithm/blob/master/Algorithm/LinkedList/BJ5397.cpp)

- Struct
```cpp
struct node {
	char c;
	struct node* next;
	struct node* prev;
};

struct cursor {
	int count;
	struct node* point;
};
```

- Insert
```cpp
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
```

- Erase
```cpp
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
```

- Move
```cpp
void moveLeft(struct cursor* curr) {
	if (curr->point->prev == NULL)
		return;
	else
		curr->point = curr->point->prev;
}
```
