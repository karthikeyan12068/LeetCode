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
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]==1){
	                grid[i][j]=INT_MAX;
	            }
	        }
	    }
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	           if(grid[i][j]==0){
	               set<pair<int,int>>s;
	               s.insert({i,j});
	                queue<pair<int,int>>q;
	                q.push({i,j});
	                int ans=INT_MAX;
	                while(ans==INT_MAX){
	                    int x=q.size();
	                    while(x--){
	                        auto node=q.front();
	                        q.pop();
	                        for(auto it:pos){
	                            int x=it.first+node.first;
	                            int y=it.second+node.second;
	                            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size()){
	                                int bef=s.size();
	                                s.insert({x,y});
	                                if(s.size()==bef){
	                                    continue;
	                                }
	                                if(grid[x][y]==INT_MAX || grid[x][y]!=0){
	                                    if(grid[x][y]==INT_MAX){
	                                        ans=min(ans,abs(x-i)+abs(y-j));
	                                    }
	                                    else{
	                                        q.push({x,y});
	                                    }
	                                }
	                                else{
	                                    q.push({x,y});
	                                }
	                            }
	                        }
	                    }
	                }
	                grid[i][j]=ans;
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