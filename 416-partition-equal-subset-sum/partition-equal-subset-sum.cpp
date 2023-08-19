class Solution {
public:
    int dp[201][20001];
    bool ret(vector<int>& nums,int i,int sum,int &tot){
        if(i==nums.size()){
            if(tot-sum==sum){
                return true;
            }
            return false;
        }
        if(dp[i][sum]!=-1){
            if(dp[i][sum]==0){
                return true;
            }
            return false;
        }
        int take=false,ntake=false;
        if(sum+nums[i]<=tot/2){
            take=take || ret(nums,i+1,sum+nums[i],tot);
        }
        ntake=ntake || ret(nums,i+1,sum,tot);
        bool ans=take||ntake;
        if(ans==false){
            dp[i][sum]=1;
        }
        else{
            dp[i][sum]=0;
        }
        return take || ntake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        return ret(nums,0,0,sum);
    }
};