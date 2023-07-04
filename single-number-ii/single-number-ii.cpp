class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
        for(int i=0;i<nums.size();i++){
            ones=nums[i]^ones;
            ones=ones&(~twos);
            twos=twos^nums[i];
            twos=twos&(~ones);
        } 
        return ones;
    }
};