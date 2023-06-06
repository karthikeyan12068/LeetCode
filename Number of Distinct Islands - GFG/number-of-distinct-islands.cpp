//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return "";
        }
        string pos1="",pos2="",pos3="",pos4="";
        grid[i][j]=-1;
        if(i+1<grid.size()){
            if(grid[i+1][j]==1){
                pos1="D"+dfs(grid,i+1,j);
            }
        }
        if(j+1<grid[0].size()){
            if(grid[i][j+1]==1){
                pos2="R"+dfs(grid,i,j+1);
            }
        }
        if(i-1>=0){
            if(grid[i-1][j]==1){
                pos3="U"+dfs(grid,i-1,j);
            }
        }
        if(j-1>=0){
            if(grid[i][j-1]==1){
                pos4="L"+dfs(grid,i,j-1);
            }
        }
        return pos1+pos2+pos3+pos4+"$";
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<string>s;
        int r=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    string ans="C"+dfs(grid,i,j);
                    int b=s.size();
                    s.insert(ans);
                    if(b!=s.size()){
                        r++;
                    }
                }
            }
        }
        return r;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends