class Solution {
public:
    long long int ret(vector<int>& nums,long long int i,long long int prev,long long int x,vector<vector<long long int>>&dp){
        if(i==nums.size()){
            return 1;
        }
        long long int ans=0;
        if(dp[prev+1][x]!=-1){
            return dp[prev+1][x];
        }
        for(long long int j=0;j<nums.size();j++){
            if((x>>(j+1)&1)==1){
                continue;
            }
            if(i==0 || nums[j]%nums[prev]==0 || nums[prev]%nums[j]==0){
                ans+=ret(nums,i+1,j,x^(1<<(j+1)),dp);
            }
        }
        return dp[prev+1][x]=ans%1000000007;
    }
    int specialPerm(vector<int>& nums) {
        long long int x=0;
        vector<vector<long long int>>dp(nums.size()+1, vector<long long int>(100000,-1));
        return ret(nums,0,-1,x,dp);
    }
};