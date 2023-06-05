//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool dfs(int i,int j,vector<vector<char>> &mat){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()){
            return false;
        }
        if(mat[i][j]=='X' || mat[i][j]=='$'){
            return true;
        }
        mat[i][j]='$';
        bool pos1=dfs(i+1,j,mat);
        bool pos2=dfs(i,j+1,mat);
        bool pos3=dfs(i-1,j,mat);
        bool pos4=dfs(i,j-1,mat);
        bool ans=false;
        if(pos1==true && pos2==true && pos3==true && pos4==true){
            ans=true;
        }
        if(ans==true){
            mat[i][j]='P';
        }
        else{
            mat[i][j]='*';
        }
        return ans;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                if(grid[i][j]=='O' || grid[i][j]=='P'){
                    bool ans=dfs(i,j,grid);
                    if(ans==true){
                        grid[i][j]='X';
                    }
                    else{
                        grid[i][j]='*';
                    }
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='*' || grid[i][j]=='P'){
                    grid[i][j]='O';
                }
            }
        }
        return grid;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends