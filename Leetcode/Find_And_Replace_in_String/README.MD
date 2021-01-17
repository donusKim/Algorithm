## Find_And_Replace_in_String
- [문제링크](https://leetcode.com/problems/find-and-replace-in-string/)
- **문제요약**
> 
- **내 풀이**
> 
- **시간 복잡도**   
>
```python
class Solution(object):
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        sources_len=len(sources)
        source_dict={}
        for i in range(sources_len):
            source_dict[indexes[i]]=[sources[i],targets[i]]
        source_dict=sorted(source_dict.items())
        end=0
        ans=""
        print(source_dict)
        for source in source_dict:
            print(end)
            ans+=S[end:source[0]]
            src_len=len(source[1][0])
            end=source[0]+src_len
            if S[source[0]:source[0]+src_len]==source[1][0]:
                ans+=source[1][1]
            else:
                ans+=S[source[0]:source[0]+src_len]
        ans+=S[end:]
        return ans
```
- **더 간결한 풀이코드**
> 
- **시간 복잡도**   
>
```python    
class Solution(object):
    def findReplaceString(self, S, indices, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """

        modified = list(S)
        for index, source, target in zip(indices, sources, targets):
            if not S[index:].startswith(source):
                continue
            else:
                modified[index] = target
                for i in range(index+1, len(source) + index):
                    modified[i] = ""

        return "".join(modified)
```

- **요약**   
> 