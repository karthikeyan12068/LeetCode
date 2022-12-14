class Solution {
public:
    int ret(vector<int>&ans,int sum,int i,int &max1,vector<int>&dp){
        if(i<0){
            max1=max(max1,sum);
            return 0;
        }
        if(dp[i]!=-1){
            max1=max(max1,sum+dp[i]);
            return dp[i];
        }
        int inc=ans[i]+ret(ans,sum+ans[i],i-2,max1,dp);
        int ninc=0+ret(ans,sum+0,i-1,max1,dp);
        return dp[i]=max(inc,ninc);
    }
    int rob(vector<int>& nums) {
        int i=0,max1=-1,sum=0;
        vector<int>dp(nums.size(),-1);
        ret(nums,sum,nums.size()-1,max1,dp);
        return max1;
    }
};