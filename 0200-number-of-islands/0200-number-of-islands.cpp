class Solution {
public:
    void dfs(vector<vector<char>>&v1,int i,int j,int r,int c){
        if(i<0 || j<0 || i>r-1 || j>c-1 || v1[i][j]=='-' || v1[i][j]=='0'){
            return;
        }
        v1[i][j]='-';
        dfs(v1,i-1,j,r,c);
        dfs(v1,i+1,j,r,c);
        dfs(v1,i,j-1,r,c);
        dfs(v1,i,j+1,r,c);
        return;
    }
    int numIslands(vector<vector<char>>&v1) {
        int r=v1.size();
        int c=v1[0].size();
        int z=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(v1[i][j]=='1'){
                    z++;
                    dfs(v1,i,j,r,c);
                }
            }
        }
        return z;
    }
};