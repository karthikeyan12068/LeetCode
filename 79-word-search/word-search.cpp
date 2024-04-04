class Solution {
public:
    int dp[16][16][16];
    bool ret(vector<vector<char>>& board, string &word,int i,int x,int y,vector<pair<int,int>>&moves){
        if(i==word.length()){
            return true;
        }
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]=='$' || board[x][y]!=word[i]){
            return false;
        }
        
        bool ans=true;
        char cur=board[x][y];
        board[x][y]='$';
        for(auto it:moves){
            ans=ans && ret(board,word,i+1,x+it.first,y+it.second,moves);
            if(ans==false){
                ans=true;
            }else{
                board[x][y]=cur;
                dp[i][x][y]=1;
                return true;
            }
        }
        board[x][y]=cur;
        dp[i][x][y]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>>pos={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(ret(board,word,0,i,j,pos)){
                    return true;
                }
            }
        }
        return false;
    }
};