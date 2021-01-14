## ZigZag_Conversion

- [문제링크](https://leetcode.com/problems/zigzag-conversion/)
- **문제요약**
> 문자열을 입력받고 지그재그 모양으로 배치한다. (밑으로 갔다가 우상향으로 올라오는걸 반복)  
> 배치가 끝난 후 위에서부터 순서대로 읽은 문자열을 반환하는 문제
- **내 풀이**
> 문자열 길이를 n이라 하자. O(n)의 시간으로 문자열을 탐색하면서 문자가 위치하는    
> rownum(mod)을 key로 하는 딕셔너리(s_dict)를 완성한다.    
> 그 결과 생기는 딕셔너리는 각 Row마다 문자의 배열들을 갖는다.    
> s_dict가 완성되면 0~rowNum-1까지의 나머지 마다 문자를 차례대로 읽는다    
- **시간 복잡도**   
> O(N)인데 append대신 문자끼리 +연산으로 바꾸면 실행속도가 훨씬 빨라진다    
>  s_dict[mod]=letter로 바꾸고 s_dict[mod]+=letter로 바꾸면 빨라진다
```python
class Solution(object):
    def convert(self, s, numRows):
        """       :type s: str
        :type numRows: int
        :rtype: str
        """
        s_list=list(s)
        length=len(s_list)
        s_dict={}
        mod=0
        num=0
        idx=1
        for letter in s_list:
            if mod==0:
                if mod not in s_dict:
                    s_dict[mod]=[letter]
                else:
                    s_dict[mod].append(letter)
                idx=1
                mod+=1
                if numRows<2:
                    mod-=1
                    num+=1
            elif mod==numRows-1:
                if mod not in s_dict:
                    s_dict[mod]=[letter]
                else:
                    s_dict[mod].append(letter)
                idx=0
                mod-=1
                num+=1
            else:
                if idx>0:
                    if mod not in s_dict:
                        s_dict[mod]=[letter]
                    else:
                        s_dict[mod].append(letter)
                    mod+=1    
                else:
                    if mod not in s_dict:
                        s_dict[mod]=[letter]
                    else:
                        s_dict[mod].append(letter)
                    mod-=1
                    num+=1
                    
        ans=""
        print(s_dict)
        for remain in range(numRows):
            if remain>length-1:
                break
            for item in s_dict[remain]:
                ans+=item
        return ans
```

- **상위 1%풀이**
> 배열에 rowNum 만큼 '' 즉 빈 문자열을 만든다.    
> 문자열을 돌면서 각자 위치에 알맞는 ''에 문자를 더해준다    
> 가장 밑에나 위에 도달하면 step의 부호를 바꿔준다   
- **시간 복잡도**   
> O(N)이고 문자열 연산이 최적화 되어있다. (.join()과 문자끼리 '+'로)   
```python
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or numRows >= len(s):
            return s

        L = [''] * numRows
        index, step = 0, 1

        for x in s:
            L[index] += x
            if index == 0:
                step = 1
            elif index == numRows -1:
                step = -1
            index += step

        return ''.join(L)
```

- **요약**   
> Big-O 방법으로 시간복잡도는 결국 동일하고 step부호 바꿔주는 Logic도 똑같다    
> 코드 품질의 차이는 문자열을 얼마나 잘 다루는냐에서 갈렸다.    
> 문자열 다룰때는 굳이 list로 만들어서 append 보단 +나 .join()사용하자!