class Solution {
public:
    int ret(int amount, vector<int>& coins,int i,vector<vector<int>>&dp){
        if(i==coins.size()){
            if(amount==0){
                return 1;
            }
            return 0;
        }
        if(amount==0){
            return 1;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int ntake=ret(amount,coins,i+1,dp);
        int take=0;
        if(amount-coins[i]>=0){
            take=ret(amount-coins[i],coins,i,dp);
        }
        return dp[i][amount]=take+ntake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return ret(amount,coins,0,dp);
    }
};