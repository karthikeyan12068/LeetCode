//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    vis[i][j]=0;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0){
                    if(vis[i][j]!=0){
                        vis[i][j]=1;
                    }
                }
                else{
                    if(vis[i][j]!=0){
                        if(i!=0 && j!=0){
                            vis[i][j]=vis[i][j-1]+vis[i-1][j];
                        }
                        else{
                            if(i==0 && j!=0){
                                vis[i][j]=vis[i][j-1];
                            }
                            else{
                               if(i!=0 && j==0){
                                   vis[i][j]=vis[i-1][j];
                               }
                            }
                        }
                    }
                }
                vis[i][j]=vis[i][j]%1000000007;
            }
        }
        return vis[n-1][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends