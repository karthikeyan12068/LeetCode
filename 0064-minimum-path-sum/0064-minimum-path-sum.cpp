class Solution {
public:
    int helper(int i,int j,int r,int c,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==r-1 && j==c-1){
            return grid[i][j];
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int right=INT_MAX,left=INT_MAX;
        if(i!=r-1){
            right=grid[i][j]+helper(i+1,j,r,c,grid,dp);
        }
        if(j!=c-1){
            left=grid[i][j]+helper(i,j+1,r,c,grid,dp);
        }
        return dp[i][j]=min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        return helper(0,0,grid.size(),grid[0].size(),grid,dp);
    }
};