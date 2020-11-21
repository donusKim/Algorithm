# BIT (Binary Indexed Tree)
- BIT 자료구조의 핵심
>  x&(-x)는 가장 오른쪽 1의 값을 나타낸다 
>> ex)  이진법으로 x=1100이면 -x=11..110100이 돼서 x&(-x)는 100이된다,,가장오른쪽 1만남은,,10진수로는 4
```cpp
void insert(int idx, int value) {
	int x = idx;
	while (x < N + 1) {
		Aarr[x] += value;
		x += x & (-x);
	}
}
```

```cpp
int getSum(int idx) {
	int x = idx;
	int sum = 0;
	while (x > 0) {
		sum += Aarr[x];
		x -= x & (-x);
	}
	return sum;
} 
```
