class Solution {
public:
    int dp[100][10001];
    int ret(int i,int n){
        if(n==0){
            return 0;
        }
        if(n<0 || i*i>n){
            return 1e7;
        }
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        int pos1=INT_MAX,pos2=INT_MAX,pos3=INT_MAX;
        int sq=i*i;
        pos1=1+ret(i,n-sq);
        pos2=1+ret(i+1,n-sq);
        pos3=0+ret(i+1,n);
        return dp[i][n]=min(pos1,min(pos2,pos3));
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return ret(1,n);
    }
};