class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),INT_MIN);
        for(int i=0;i<arr.size();i++){
            int maxe=INT_MIN;
            for(int j=i;j>=max(0,i-(k-1));j--){
                maxe=max(maxe,arr[j]);
                if(j-1>=0){
                    dp[i]=max(dp[i],(maxe)*((i-j)+1)+dp[j-1]);
                }
                else{
                    dp[i]=max(dp[i],(maxe)*((i-j)+1));
                }
                
            }
            //cout<<dp[i]<<'\n';
        }
        return dp[arr.size()-1];
    }
};