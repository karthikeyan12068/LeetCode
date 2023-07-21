class Solution {
public:
    
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        vector<int>cnt(nums.size(),1);
        for(int cur=1;cur<nums.size();cur++){
            for(int prev=0;prev<cur;prev++){
                if(nums[cur]>nums[prev]){
                    if(dp[prev]+1>dp[cur]){
                        dp[cur]=dp[prev]+1;
                        cnt[cur]=cnt[prev];
                    }
                    else{
                        if(dp[prev]+1==dp[cur]){
                            cnt[cur]+=cnt[prev];
                        }
                    }
                }
            }
        }
        int x=*max_element(dp.begin(),dp.end());
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==x){
                c+=cnt[i];
            }
        }
        return c;
    }
};