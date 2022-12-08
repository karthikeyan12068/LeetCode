class Solution {
public:
    int check(vector<vector<int>>& nums,int r,int c,vector<vector<int>>&dp)
    {
          if(r==nums.size()||c>nums[r].size())
            return 0;
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
     return dp[r][c]=nums[r][c]+min(check(nums,r+1,c,dp),check(nums,r+1,c+1,dp));
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<vector<int>>dp(row,vector<int>(row,-1));
        int sol=INT_MAX;
        sol=check(triangle,0,0,dp);
     return sol;
    }
};