## Back-Tracking

### 1. 연산자 끼워놓기
- [문제링크](https://www.acmicpc.net/problem/14888)
- [풀이코드](https://github.com/donusKim/Algorithm/blob/master/baekjoon/Back-Tracking/bj_14888.cpp)
- **문제요약**
> 숫자 배열이 주어지고 그사이에 사친연산을 끼워넣어 만들 수 있는 결과값의 최대와 최소값을 구해야 하는 문제.
- **메인로직** 
> 모든 경우의수를 다 계산해보고(dfs) 최대 최소 발생할 때 마다 업데이트 해준다. 주의할 점은 최대 최소의 초기값을 설정. 
```cpp
void dfs(int step, long long cusum, int plus, int minus, int mul, int div) {
    if (step == arrLen - 1) {
		if (cusum > max)
			max = cusum;
		if (min > cusum)
			min = cusum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			if (plus > 0)
				dfs(step + 1, cusum + arr[step + 1], plus - 1, minus, mul, div);
			else continue;
		}
		else if (i == 1) {
			if (minus > 0)
				dfs(step + 1, cusum - arr[step + 1], plus, minus - 1, mul, div);
			else continue;
		}
		else if (i == 2) {
			if (mul > 0)
				dfs(step + 1, cusum*arr[step + 1], plus, minus, mul - 1, div);
			else continue;
		}
		else {
			if (div > 0)
				dfs(step + 1, divide(cusum, arr[step + 1]), plus, minus, mul, div - 1);
			else continue;
		}
	}
	return;
}
```
### 2. 스도쿠
- [문제링크](https://www.acmicpc.net/problem/2580)
- [풀이코드](https://github.com/donusKim/Algorithm/blob/master/baekjoon/Back-Tracking/bj_2580.cpp)
- **문제요약**
> 9x9 정사각형 판이 주어져있다. 1~9까지의 수들이 채워져있는데 빈칸도 존재한다. 빈칸을 스도쿠 규칙에 맞게 채우는 문제.
- **메인로직**
> (0,0)부터 (8,8)까지 차례대로 순회한다. 빈칸을 만나면 1~9까지의 수를 채워넣기 위해 검사한다. 모든 빈칸을 채우면 breakIdx가 하나 증가되고 종료
- **Traverse함수**
```cpp
void traverse(int x, int y){
    if(map[x][y]>0){
        if(x==size-1 && y==size-1){
            breakIdx++;
            return;
        }
        if(y<size-1)
            traverse(x,y+1);
        else
            traverse(x+1,0);    
    }
    else{
        for(int num=1;num<10;num++){
            if(inspect(x,y,num)){
                map[x][y]=num;
                if(x==size-1 && y==size-1){
                    breakIdx++;
                    return;        
                }
                if(y<size-1)
                    traverse(x,y+1);
                else
                    traverse(x+1,0);
                if(breakIdx>0)
                    return;
                map[x][y]=0;
            }
        }
    }    
}
```
- **inspect함수**
```cpp
int inspect(int x, int y, int n){
    for(int i=0;i<9;i++){
        if(map[x][i]==n)
            return 0;
    }
    for(int i=0;i<9;i++){
        if(map[i][y]==n)
            return 0;
    }
    int cornerX=(x/3)*3;
    int cornerY=(y/3)*3;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(map[cornerX+i][cornerY+j]==n)
                return 0;
        }    
    }
    return 1;   
}
```
