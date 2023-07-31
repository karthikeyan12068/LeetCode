class Solution:
    
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        list1=list(s1)
        list2=list(s2)
        
        @cache
        def ret(i,j):
               
            if (i==len(s1) or j==len(s2)):
                i1=i 
                j1=j
                ans=0
                while (i1<len(s1)):
                    ans+=ord(s1[i1])
                    i1+=1
                while (j1<len(s2)):
                    ans+=ord(s2[j1])
                    j1+=1
                return ans
            ans=float("-inf")
            if(s1[i]==s2[j]):
                ans=0+ret(i+1,j+1)
            else:
                ans=min(ord(s1[i])+ret(i+1,j),ord(s2[j])+ret(i,j+1))
            return ans
        
        return ret(0,0)
        
        
        