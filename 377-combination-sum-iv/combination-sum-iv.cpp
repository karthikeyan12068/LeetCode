class Solution {
public:
    int dp[1001];
    int ret(vector<int>& nums, int target){
        if(target==0){
            return 1;
        }
        int ways=0;
        if(dp[target]!=-1){
            return dp[target];
        }
        for(auto it:nums){
            if(it<=target){
                ways+=ret(nums,target-it);
            }
        }
        return dp[target]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return ret(nums,target);
    }
};