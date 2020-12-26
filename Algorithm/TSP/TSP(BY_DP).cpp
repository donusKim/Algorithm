#include <stdio.h>
#define INF 1000000000
int N;
int Weight[17][17];
int cache[17][70000];
int visited;
int tsp(int, int);
int main() {
	// step 1: 입력받기
	scanf("%d", &N);
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			scanf(" %d", &Weight[row][col]);
		}
	}
	// step 2: 0번 node 방문(첫번째 자리에 1표시) 
	visited = visited | (1 << 0);
	// step 3: tsp 함수 실행, 함수의 return 값은 없고 전역변수 Min을 최소값으로 update하는 기능 수행
	int ans;
	ans=tsp(0, visited);
	// step 4: 정답출력
	printf("%d", ans);
	return 0;
}

// 현재 노드와 지금까지 방문한 이력을 인자로 받아 남은 노드들을 방문하는데 걸리는 최소거리를 return 함
int tsp(int here, int visited) {
	// 이미 구한값이면 구한값을 배열에서 그대로 읽어서 return
	if (cache[here][visited] != 0)
		return cache[here][visited];
	
	// 다 방문했으면 현재 node에서 출발노드까지의 거리 return
	if (visited == (1 << N) - 1 && Weight[here][0] != 0) {
		return Weight[here][0];
	}
	int min = INF;
	int new_visited;
	for (int next = 0; next < N; next++) {		
		// 방문하지 않았고 현재 node와 연결되어있는 노드라면 탐색
		if (!(visited & (1 << next)) && Weight[here][next] > 0) {
			new_visited = visited | (1 << next);
			min = tsp(next, new_visited) + Weight[here][next] < min ? tsp(next, new_visited) + Weight[here][next] : min;
		}
	}
	// cache배열에 저장
	cache[here][visited]=min;
	return min;
}
