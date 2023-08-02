class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        @cache
        def fact(n):
            if n<=0:
                return 1
            return n*fact(n-1)

        val=fact(len(nums))
        ans=[]
        ans.append(list(nums))

        def ret():
            #function that gives the next smallest permuatation for current array
            for j in range(len(nums)-2,-1,-1):
                ind=-1
                val1=float("inf")
                for k in range(j+1,len(nums),1):
                    if(val1>nums[k] and nums[k]>nums[j]):
                        ind=k
                        val1=nums[k]
                if ind!=-1:
                    nums[j],nums[ind]=nums[ind],nums[j]
                    temp=[]
                    for k in range(j+1,len(nums),1):
                        temp.append(nums[k])
                    temp.sort()
                    x=0
                    for k in range(j+1,len(nums),1):
                        nums[k]=temp[x]
                        x+=1
                    return
            return
        for i in range(val-1):
            #for every factorial iter we update array once
            ret()
            ans.append(list(nums))
        return ans