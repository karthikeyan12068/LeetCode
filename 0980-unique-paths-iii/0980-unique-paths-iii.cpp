class Solution {
public:
    int dfs(vector<vector<int>>grid,int x,int y,int z){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==-1){
            return 0;
        }
        if(grid[x][y]==2 && z==-1){
            return 1;
        }
        z--;
        grid[x][y]=-1;
        return dfs(grid,x+1,y,z)+dfs(grid,x,y+1,z)+dfs(grid,x-1,y,z)+dfs(grid,x,y-1,z);
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int z=0,x=0,y=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    z++;
                }
                if(grid[i][j]==1){
                    x=i,y=j;
                }
            }
        }
        
        return dfs(grid,x,y,z);
    }
};