class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        remsum=sum(nums)-x
        if(remsum<0):
            return -1
        if(remsum==0):
            return len(nums)
        l=0
        r=0
        cursum=0
        ans=-1
        while(r<len(nums)):
            cursum+=nums[r]
            if(cursum==remsum):
                if(ans==-1):
                    ans=l+((len(nums)-r)-1)
                else:
                    ans=min(ans,l+((len(nums)-r)-1))
            if(cursum>remsum):
                while(l<=r and cursum>remsum):
                    cursum-=nums[l]
                    l+=1
                    if(cursum==remsum):
                        if(ans==-1):
                            ans=l+((len(nums)-r)-1)
                        else:
                            ans=min(ans,l+((len(nums)-r)-1))
            r+=1

        return ans

