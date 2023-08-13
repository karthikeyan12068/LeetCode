class Solution {
public:
    int dp[100001];
    bool ret(vector<int>& nums,int i){
        if(i==nums.size()){
            return true;
        }
        if(dp[i]!=-1){
            if(dp[i]==0){
                return true;
            }
            return false;
        }
        bool ans=false;
        if(i+1<=nums.size()-1){
            if(nums[i]==nums[i+1]){
                ans=ans|ret(nums,i+2);
            }
        }
        if(i+2<=nums.size()-1){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                ans=ans|ret(nums,i+3);
            }
            if(nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]){
                ans=ans|ret(nums,i+3);
            }
        }
        if(ans==false){
            dp[i]=1;
        }
        else{
            dp[i]=0;
        }
        return ans;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return ret(nums,0);
    }
};