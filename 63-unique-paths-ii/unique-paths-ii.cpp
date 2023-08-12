class Solution {
public:
    int dp[101][101];
    int ret(vector<vector<int>>&grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1 || grid[i][j]==-1){
            return 0;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int temp=grid[i][j];
        grid[i][j]=-1;
        int pos1=ret(grid,i+1,j);
        int pos2=ret(grid,i,j+1);
        grid[i][j]=temp;
        return dp[i][j]=pos1+pos2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        memset(dp,-1,sizeof(dp));
        return ret(grid,0,0);
    }
};