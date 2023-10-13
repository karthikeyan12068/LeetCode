class Solution {
public:
    int dp[1001];
    int ret(vector<int>& cost,int i){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        if(i==0){
            ans=min(ans,0+ret(cost,i+1));
        }
        ans=min(ans,cost[i]+min(ret(cost,i+1),ret(cost,i+2)));
        return dp[i]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return ret(cost,0);
    }
};