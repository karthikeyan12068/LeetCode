class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int>r0(grid.size()),r1(grid.size());
        for(int i=0;i<grid.size();i++){
            int z=0,o=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    z++;
                }
                else{
                    o++;
                }
            }
            r0[i]=z;
            r1[i]=o;
        }
        vector<int>c0(grid[0].size()),c1(grid[0].size());
        for(int j=0;j<grid[0].size();j++){
            int z=0,o=0;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]==0){
                    z++;
                }
                else{
                    o++;
                }
            }
            c0[j]=z;
            c1[j]=o;
        }
        vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans[i][j]=r1[i]+c1[j]-r0[i]-c0[j];
            }
        }
        return ans;
    }
};