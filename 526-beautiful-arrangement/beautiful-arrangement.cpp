class Solution {
public:
    int dp[16][1<<16];
    int ret(int i,int x,int &n){
        if(i>n){
            return 1;
        }
        if(dp[i][x]!=-1){
            return dp[i][x];
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            if(((x>>j)&1)==0){
               if(i%j==0 || j%i==0){
                   ans+=ret(i+1,(x^(1<<j)),n);
               }
            }
        }
        return dp[i][x]=ans;
    }
    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
        return ret(1,0,n);
    }
};