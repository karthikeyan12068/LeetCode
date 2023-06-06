//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>>q;
        int sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    sum++;
                }
                if(grid[i][j]==1 && (i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1)){
                    q.push({i,j});
                }
            }
        }
    
        vector<pair<int,int>>pos={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int x=q.size();
            while(x--){
                auto node=q.front();
                q.pop();
                sum--;
                grid[node.first][node.second]=-1;
                for(auto it:pos){
                    int x1=node.first+it.first;
                    int y1=node.second+it.second;
                    if(x1>=1 && y1>=1 && x1<grid.size()-1 && y1<grid[0].size()-1 && grid[x1][y1]==1){
                        grid[x1][y1]=-1;
                        q.push({x1,y1});
                    }
                }
            }
        }
        return sum;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends