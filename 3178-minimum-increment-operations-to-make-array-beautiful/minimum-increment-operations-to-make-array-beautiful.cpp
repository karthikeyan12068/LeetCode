class Solution {
public:
    long long dp[100001];
    long long ret(vector<int>& nums, int &k,int i){
        
        if(i+2<nums.size()){
            if(dp[i]!=-1){
                return dp[i];
            }
            long long max1=max(nums[i],max(nums[i+1],nums[i+2]));
            long long ans=LONG_MAX;
            if(max1<k){
                for(int j=i;j<=i+2;j++){
                    long long diff=k-nums[j];
                    ans=min(ans,diff+ret(nums,k,j+1));
                }
            }
            else{
                ans=0+ret(nums,k,i+1);
            }
            return dp[i]=ans;
        }
        return dp[i]=0;
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return ret(nums,k,0);
    }
};