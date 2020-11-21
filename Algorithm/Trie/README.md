# TRIE 
- 개요
>  Trie란 이름은 retrieval의 약자이다   
문자열 탐색에 특화된 자료구조이다

- Trie Node 정의
> cnt가 0보다 크면 끝이라는 뜻. 즉 지금 까지 간선(alphabet)을 합친 단어가 cnt개수만큼 자료구조에 존재, 0이면 아직 끝이아니고 현재까지 간선합한 단어 자료구조에 없다는 뜻이다      
next배열은 포인터배열이다. 배열의 크기는 알파벳 수(26개)만큼이며 한 노드당 최대 26개의 간선이 뻣어있다      
여기서 뻣어 있다는 것은 포인터 배열값이 NULL값이 아닐 경우를 말한다.
```cpp
typedef struct _trieNode trieNode;
struct _trieNode {
	int cnt;
	trieNode *next[alphabetSize];
};
```
- Trie Tree 정의
> count는 Tree에 저장된 총 자료의 개수를 나타냄    
rootNode는 빈 Node이다
```cpp
typedef struct _trie trie;
struct _trie{
	// 총 자료 개수
	int count;
	// root노드(빈 노드)
	trieNode *rootNode;
};
```
- Trie Tree 초기화 
> 초기화 할 Tree의 주소값을 입력으로 넣는다
```cpp
void initTrie(trie * trieTree) {
	trieTree->rootNode = newNode();
	trieTree->count = 0;
}```

- Trie Node 초기화 
> 초기화된 trieNode를 반환
```cpp
trieNode * newNode(void) {
	trieNode * newTrieNode = (trieNode *)malloc(sizeof(trieNode));
	newTrieNode->cnt = 0;
	for (int i = 0; i < alphabetSize; i++) {
		newTrieNode->next[i] = NULL;
	}
	return newTrieNode;
}
}
```

- Tree에 자료를 넣는다 
> Trie tree에 word를 Insert
```cpp
void insert(trie * trieTree, char word[]) {
	int wordLen = stringSize(word);
	trieNode * start = trieTree->rootNode;
	for (int i = 0; i < wordLen; i++) {
		// 없을 때 새로운 node생성
		if(!start->next[alphabetToIndex(word[i])])
			start->next[alphabetToIndex(word[i])] = newNode();
		start = start->next[alphabetToIndex(word[i])];
	}
	//마지막 노드의 last를 하나 더해준다
	start->cnt++;
}
```

- Tree에 자료가 있는지 검사
> Trie tree에 word가 있으면 1 return 없으면 0 return
```cpp
int inspect(trie * trieTree, char word[]) {
	int wordLen = stringSize(word);
	trieNode *start = trieTree->rootNode;
	for (int i = 0; i < wordLen; i++) {
		if (!start->next[alphabetToIndex(word[i])])
			return 0;
		start = start->next[alphabetToIndex(word[i])];
	}
	if(start->cnt>0)
		return 1;
	return 0;
}
```

> [C로 작성된 TRIE자료구조 Code](https://github.com/donusKim/Algorithm/blob/master/Algorithm/BIT/BIT.cpp)

