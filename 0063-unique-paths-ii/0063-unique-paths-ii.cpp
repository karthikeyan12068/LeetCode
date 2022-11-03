class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& v1,vector<vector<int>>&dp){
        if(v1[i][j]==1){
            return 0;
        }
        if(i==v1.size()-1 && j==v1[0].size()-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=0,down=0;
        if(i+1<=v1.size()-1){
            right=helper(i+1,j,v1,dp);
        }
        if(j+1<=v1[0].size()-1){
            down=helper(i,j+1,v1,dp);
        }
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v1) {
        vector<vector<int>>dp(v1.size(),vector<int>(v1[0].size(),-1));
        return helper(0,0,v1,dp);
    }
};