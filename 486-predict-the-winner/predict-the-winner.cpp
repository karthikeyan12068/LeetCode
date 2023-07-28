class Solution {
public:
    int ret(vector<int>&nums,int i,int j,int chance, vector<vector<vector<int>>>&dp){
        if(i>j){
            return 0;
        }
        int fr,bk;
        if(dp[i][j][chance]!=-1){
            return dp[i][j][chance];
        }
        if(chance==0){
            fr=nums[i]+ret(nums,i+1,j,1,dp);
            bk=nums[j]+ret(nums,i,j-1,1,dp);
        }
        if(chance==1){
            fr=-nums[i]+ret(nums,i+1,j,0,dp);
            bk=-nums[j]+ret(nums,i,j-1,0,dp);
        }
        if(chance==0){
            return dp[i][j][chance]=max(fr,bk);
        }
        return dp[i][j][chance]=min(fr,bk);
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,-1)));
        int val=ret(nums,0,nums.size()-1,0,dp);
        if(val>=0){
            return true;
        }
        return false;
    }
};