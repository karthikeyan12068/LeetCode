class Solution {
public:
    int dp[101][101];
    int ret(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int i,int j){
        int ans=1e9;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i!=grid.size()-1){
            for(int k=0;k<moveCost[grid[i][j]].size();k++){
                ans=min(ans,grid[i][j]+moveCost[grid[i][j]][k]+ret(grid,moveCost,i+1,k));
            }
        }
        else{
            for(int k=0;k<moveCost[grid[i][j]].size();k++){
                ans=min(ans,grid[i][j]);
            }
        }
        return dp[i][j]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans=1e9;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<grid[0].size();i++){
            ans=min(ans,ret(grid,moveCost,0,i));
        }
        return ans;
    }
};