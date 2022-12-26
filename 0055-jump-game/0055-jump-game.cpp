class Solution {
public:
   
    bool canJump(vector<int>& nums) {
        int st=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+nums[i]>=st){
                st=i;
            }
        }
        if(st==0){
            return true;
        }
        return false;
    }
};