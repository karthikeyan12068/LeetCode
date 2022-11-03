class Solution {
public:
    int helper(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m || j==n){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=helper(i,j+1,m,n,dp);
        int down=helper(i+1,j,m,n,dp);
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(1,1,m,n,dp);
    }
};