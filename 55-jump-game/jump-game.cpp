class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fin=-1;
        if(nums.size()==1){
            return true;
        }
        for(int i=0;i<nums.size();i++){
            if(i==0){
                fin=i+nums[i];
            }
            else{
                if(i>fin){
                    return false;
                }
                else{
                    if(i+nums[i]>fin){
                        fin=i+nums[i];
                    }
                }
            }
        }
        if(fin>=nums.size()-1){
            return true;
        }
        return false;
    }
};