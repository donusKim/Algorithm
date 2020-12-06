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
