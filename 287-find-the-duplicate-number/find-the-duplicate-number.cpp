class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]--;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums.size()){
                if(nums[nums[i]]+nums.size()>=2*nums.size()){
                    return nums[i]+1;
                }
                nums[nums[i]]+=nums.size();
            }
            else{
                if(nums[nums[i]-nums.size()]+nums.size()>=2*nums.size()){
                    return nums[i]-nums.size()+1;
                }
                nums[nums[i]-nums.size()]+=nums.size();
            }
        }
        return -1;
    }
};