class Solution:
    def countSubstrings(self, s: str) -> int:
        sum=0
        for i in range(len(s)):
            str=""
            for j in range(i,len(s)):
                str+=s[j]
                if(str==str[::-1]):
                    sum+=1
        return sum