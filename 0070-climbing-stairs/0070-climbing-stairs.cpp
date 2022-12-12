class Solution {
public:
    int ret(int n,vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int d1=ret(n-1,dp);
        int d2=ret(n-2,dp);
        return dp[n]=d1+d2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return ret(n,dp);
    }
};