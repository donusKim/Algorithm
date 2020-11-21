#include <stdio.h>
#include <stdlib.h>
#define alphabetSize 26
#define alphabetToIndex(a) (int(a)-int('a'))

// 노드정의
typedef struct _trieNode trieNode;
struct _trieNode {
	// cnt가 0보다 크면 끝이라는 뜻 즉,, 지금 까지 간선(alphabet)을 합친 단어가 cnt개수만큼 자료구조에 존재, 0이면 아직 끝이아니고 현재까지 간선합한 단어 자료구조에 없음
	int cnt;
	// 포인터배열이다,,, 길이는 알파벳 수(26개)만큼이며 한 노드당 최대 26개의 간선이 뻣어있다,,, NULL값이 아닐경우 간선이 뻣어있다는 뜻이다,, 
	trieNode *next[alphabetSize];
};

// trie tree정의
typedef struct _trie trie;
struct _trie{
	// 총 자료 개수
	int count;
	// root노드(빈 노드)
	trieNode *rootNode;
};

void initTrie(trie * trieTree);
trieNode *newNode(void);
void insert(trie * trieTree, char word[]);
int inspect(trie * trieTree, char word[]);
int stringSize(char word[]);
//main함수,, Trie 자료구조 확인용
int main() {
	char words1[5][15];
	char words2[5][15];
	trie *trieTree = (trie *)malloc(sizeof(trie));
	initTrie(trieTree); 
	for (int i = 0; i < 5; i++) {
		scanf("%s", words1[i]);
		insert(trieTree, words1[i]);
	}
	for (int i = 0; i < 5; i++) {
		scanf("%s", words2[i]);
		if (inspect(trieTree, words2[i]))
			printf("%s 있습니다\n", words2[i]);
		else
			printf("%s 없습니다\n", words2[i]);
	}
	return 0;
}


//Trie트리를 입력으로 넣으면 트리를 초기화시키는 함수
void initTrie(trie * trieTree) {
	trieTree->rootNode = newNode();
	trieTree->count = 0;
}

//초기화된 trieNode를 반환하는 함수
trieNode * newNode(void) {
	trieNode * newTrieNode = (trieNode *)malloc(sizeof(trieNode));
	newTrieNode->cnt = 0;
	for (int i = 0; i < alphabetSize; i++) {
		newTrieNode->next[i] = NULL;
	}
	return newTrieNode;
}

// Trie tree에 word를 넣는다,,,
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

// Trie tree에 word가 있는지 검사
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

int stringSize(char word[]) {
	int cnt = 0;
	while (word[cnt] != '\0') cnt++;	
	return cnt;
}
