class Solution {
public:
    int dp[60];
    int ret(int n,int t){
        if(n==0){
            if(t==1 || t==1){
                return 0;
            }
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=max(ans,i*ret(n-i,t+1));
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return ret(n,0);
    }
};