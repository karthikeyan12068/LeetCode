class Solution {
public:
    void ret(vector<int>& nums, int i,int target,vector<int>temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || i==nums.size()){
            return;
        }
        temp.push_back(nums[i]);
        ret(nums,i,target-nums[i],temp,ans);
        temp.pop_back();
        ret(nums,i+1,target,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        ret(candidates,0,target,{},ans);
        return ans;
    }
};