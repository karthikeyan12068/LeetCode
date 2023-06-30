class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int tar=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            tar=min(tar,nums[mid]);
            if(nums[r]<nums[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
            
        }
        return tar;
    }
};