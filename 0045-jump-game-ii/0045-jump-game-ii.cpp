class Solution {
public:
    int helper(int i,vector<int>& nums,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(i+nums[i-1]>=nums.size()){
            return 1;
        }
        if(dp[i]!=0){
            return dp[i];
        }
        int ans=INT_MAX-1;
        for(int j=1;j<=nums[i-1];j++){
            int get=1+helper(i+j,nums,dp);
            ans=min(ans,get);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,0);
        return helper(1,nums,dp);
    }
};