//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool ret(vector<vector<char>>& grid, string &word,int i,int j,int ptr,vector<vector<vector<bool>>>&dp){
        //cout<<ptr<<'\n';
        if(ptr>=word.length()){
            return true;
        }
        
        if(i>=grid.size()||j>=grid[0].size() || i<0 || j<0){
            return false;
        }
        if(grid[i][j]!=word[ptr] || grid[i][j]=='$'){
            return false;
        }
        
        char temp=grid[i][j];
        grid[i][j]='$';
        bool pos1=ret(grid,word,i+1,j,ptr+1,dp);
        bool pos2=ret(grid,word,i-1,j,ptr+1,dp);
        bool pos3=ret(grid,word,i,j+1,ptr+1,dp);
        bool pos4=ret(grid,word,i,j-1,ptr+1,dp);
        grid[i][j]=temp;
        return dp[i][j][ptr]=pos1|pos2|pos3|pos4;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        vector<vector<vector<bool>>>dp(board.size(),vector<vector<bool>>(board[0].size(), vector<bool>(word.length(),false)));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(ret(board,word,i,j,0,dp)){
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends