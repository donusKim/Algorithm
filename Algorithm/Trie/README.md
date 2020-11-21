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
	// cnt가 0보다 크면 끝이라는 뜻 즉,, 지금 까지 간선(alphabet)을 합친 단어가 cnt개수만큼 자료구조에 존재, 0이면 아직 끝이아니고 현재까지 간선합한 단어 자료구조에 없음
	int cnt;
	// 포인터배열이다,,, 길이는 알파벳 수(26개)만큼이며 한 노드당 최대 26개의 간선이 뻣어있다,,, NULL값이 아닐경우 간선이 뻣어있다는 뜻이다,, 
	trieNode *next[alphabetSize];
};

```
> [C로 작성된 TRIE자료구조 Code](https://github.com/donusKim/Algorithm/blob/master/Algorithm/BIT/BIT.cpp)

