class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        nums.push_back(INT_MIN);
        if(nums.size()==1){
            return 0;
        }
        if(nums.size()==2){
            if(nums[0]<nums[1]){
                return 1;
            }
            return 0;
        }
        while(l<=r){
                int mid=(l+r)/2;
                if(l==r){
                    return l;
                }
                if(((mid-1>=0)?nums[mid-1]:INT_MIN)<=nums[mid] && (mid+1<nums.size()?nums[mid+1]:INT_MIN)<=nums[mid]){
                    return mid;
                }
                else{
                    if(((mid-1>=0)?nums[mid-1]:INT_MIN)<=nums[mid] && (mid+1<nums.size()?nums[mid+1]:INT_MIN)>=nums[mid]){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
           
        }
        return r;
    }
};