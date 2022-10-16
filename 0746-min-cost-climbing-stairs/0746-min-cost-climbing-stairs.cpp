class Solution {
public:
    int min1=INT_MAX;
    int ret(int n,vector<int>cost,vector<int>&dp){
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int cost1=cost[n]+ret(n-1,cost,dp);
        int cost2=cost[n]+ret(n-2,cost,dp);
        return dp[n]=min(cost1,cost2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int>dp(cost.size());
        for(int i=0;i<cost.size();i++){
            dp[i]=-1;
        }
        return ret(cost.size()-1,cost,dp);
        
    }
};