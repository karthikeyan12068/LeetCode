class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int c=col-1;c>=0;c--){
            for(int r=0;r<row;r++){
                if(c+1<col){
                    if(matrix[r][c]!='0'){
                        dp[r][c]=dp[r][c+1]+1;
                    }
                }
                else{
                    dp[r][c]=matrix[r][c]-'0';
                }
            }
        }
        /*for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<dp[i][j]<<' ';
            }
            cout<<'\n';
        }*/
        int ans=0;
        for(int i=0;i<col;i++){
            vector<int>lmin(row,-1),rmin(row,row);
            stack<int>s;
            for(int j=0;j<row;j++){
                while(!s.empty() && dp[s.top()][i]>dp[j][i]){
                    rmin[s.top()]=j;
                    s.pop();
                }
                s.push(j);
            }
            while(!s.empty()){
                s.pop();
            }
            for(int j=row-1;j>=0;j--){
                while(!s.empty() && dp[s.top()][i]>dp[j][i]){
                    lmin[s.top()]=j;
                    s.pop();
                }
                s.push(j);
            }
            for(int j=0;j<row;j++){
                int val=(rmin[j]-j)+(j-lmin[j]);
                val--;
                int a=min(dp[j][i],val);
                ans=max(ans,a*a);
            }
        }
        return ans;
    }
};