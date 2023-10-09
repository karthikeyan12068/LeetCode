class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};
        int l=0,r=nums.size()-1;
        if(nums.empty()){
           
            return {-1,-1};
        }
        while(l<=r){
            
            int mid=(l+r)/2;
            if(nums[mid]==target){
                ans={mid,mid};
                int l1=mid-1,r1=mid+1;
                while(true){
                    int f=0;
                    if(l1>=0 && nums[l1]==target){
                        ans[0]=l1;
                        l1--;
                        f=1;
                    }
                    if(r1<nums.size() && nums[r1]==target){
                        ans[1]=r1;
                        r1++;
                        f=1;
                    }
                    if(f==0){
                        return ans;
                    }
                }
            }
            if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};