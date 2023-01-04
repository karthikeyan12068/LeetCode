class Solution {
public:
    int ret(int n,vector<int>&dp){
        if(n<0){
            return 1000000;
        }
        if(n==0){
            return 0;
        }
        if(dp[n]!=INT_MAX){
            return dp[n];
        }
        int left=1+ret(n-2,dp);
        int right=1+ret(n-3,dp);
        return dp[n]=min(left,right);
    }
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m1;
        for(int i=0;i<tasks.size();i++){
            m1[tasks[i]]++;
        }
        int c=0;
        for(auto it:m1){
            vector<int>dp(it.second+1,INT_MAX);
            int ans=ret(it.second,dp);
            if(ans<=100000){
                c+=ans;
            }
            else{
                return -1;
            }
        }
        return c;
    }
};