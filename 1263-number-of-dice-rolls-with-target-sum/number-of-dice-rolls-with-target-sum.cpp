class Solution {
public:
    int dp[31][10001];
    long long int ret(int n, int &k, int target){
        if(n==0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        long long int ans=0;
        for(int i=1;i<=k;i++){
            ans+=ret(n-1,k,target-i);
            ans=ans%1000000007%1000000007%1000000007%1000000007%1000000007%1000000007%1000000007;
        }
        return dp[n][target]=ans%1000000007%1000000007%1000000007%1000000007%1000000007%1000000007;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return ret(n,k,target);
    }
};