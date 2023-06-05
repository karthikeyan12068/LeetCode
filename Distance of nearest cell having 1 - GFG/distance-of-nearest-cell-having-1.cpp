//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    vector<pair<int,int>>pos={{-1,0},{0,1},{1,0},{0,-1}};
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]==1){
	                grid[i][j]=INT_MAX;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    while(!q.empty()){
	        int x=q.size();
	        while(x--){
	            auto node=q.front();
	            q.pop();
	            for(auto it:pos){
	                int x=node.first.first+it.first;
	                int y=node.first.second+it.second;
	                int val=node.second+1;
	                if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==0){
	                    grid[x][y]=val;
	                    q.push({{x,y},val});
	                }
	            }
	        }
	    }
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]==INT_MAX){
	                grid[i][j]=0;
	            }
	        }
	    }
	    return grid;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends