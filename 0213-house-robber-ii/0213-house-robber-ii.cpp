class Solution {
public:
    int ret1(int i,vector<int>& nums,int type,vector<int>&dp){
        if(type==1){
            if(i<=0){
                return 0;
            }
        }
        if(type==2){
            if(i<0){
                return 0;
            }
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int inc=nums[i]+ret1(i-2,nums,type,dp);
        int ninc=0+ret1(i-1,nums,type,dp);
        return dp[i]=max(inc,ninc);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n=nums.size()-1;
        vector<int>dp(nums.size(),-1);
        int ans1=ret1(n,nums,1,dp);
        for(int i=0;i<nums.size();i++){
            dp[i]=-1;
        }
        int ans2=ret1(n-1,nums,2,dp);
        return max(ans1,ans2);
    }
};