class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        list1=[]
        for i in range(1,n+1):
            list1.append(i)
        
        temp=[]
        ans=[]
        def ret(i,k):
            if(k==0):
                ans.append(list(temp))
                return
            if(i==len(list1)):
                return
            temp.append(list1[i])
            ret(i+1,k-1)
            temp.pop()
            ret(i+1,k)
        ret(0,k)
        return ans
