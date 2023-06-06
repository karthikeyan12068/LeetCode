//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='O' && (i==0 || j==0 ||i==grid.size()-1 || j==grid[0].size()-1)){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>>pos={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            int x=q.size();
            while(x--){
                auto node=q.front();
                q.pop();
                grid[node.first][node.second]='*';
                for(auto it:pos){
                    int x1=node.first+it.first;
                    int y1=node.second+it.second;
                    if(x1>=1 && y1>=1 && x1<grid.size()-1 && y1<grid[0].size()-1 && grid[x1][y1]=='O'){
                        q.push({x1,y1});
                        grid[x1][y1]='*';
                    }
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='*'){
                    grid[i][j]='O';
                }
                else{
                    grid[i][j]='X';
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