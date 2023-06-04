//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int r=grid.size();
        int rem=0;
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    rem++;
                }
            }
        }
        vector<pair<int,int>>pos={{-1,0},{1,0},{0,1},{0,-1}};
        int sum=0;
        while(!q.empty()){
            int x=q.size();
            while(x--){
                auto node=q.front();
                q.pop();
                for(auto it:pos){
                    int x=node.first+it.first;
                    int y=node.second+it.second;
                    if(x>=0 && y>=0 && x<r && y<c){
                        if(grid[x][y]==1){
                            rem--;
                            grid[x][y]=2;
                            q.push({x,y});
                        }
                    }
                }
            }
            sum++;
            if(rem==0){
                return sum;
            }
        }
        return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends