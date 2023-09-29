class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int val=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                if(val==-1){
                    return false;
                }
                val=1;
            }
            if(nums[i]<nums[i-1]){
                if(val==1){
                    return false;
                }
                val=-1;
            }
        }
        return true;
    }
};