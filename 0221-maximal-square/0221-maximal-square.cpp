class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>dp;
        for(int i=0;i<r;i++){
            vector<int>v;
            for(int j=0;j<c;j++){
                v.push_back(INT_MAX);
            }
            dp.push_back(v);
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]!='0'){
                    if(i-1>=0 && j-1>=0){
                        dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
                    }
                    else{
                        dp[i][j]=1;
                    }
                }
                else{
                    dp[i][j]=0;
                }
                
                ans=max(ans,dp[i][j]);
            }
            
        }
        return ans*ans;
    }
};