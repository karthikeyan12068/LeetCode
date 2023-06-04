//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        if(grid[sr][sc]==newColor){
            return grid;
        }
        int col=grid[sr][sc];
        grid[sr][sc]=newColor;
        vector<pair<int,int>>pos={{0,1},{0,-1},{-1,0},{1,0}};
        while(!q.empty()){
            int x=q.size();
            while(x--){
                auto it=q.front();
                q.pop();
                for(auto it1:pos){
                    int x=it.first+it1.first;
                    int y=it.second+it1.second;
                    if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size()){
                        if(grid[x][y]==col){
                            grid[x][y]=newColor;
                            q.push({x,y});
                        }
                    }
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends