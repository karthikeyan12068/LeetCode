class Solution {
public:
    int dp[1002][1002][4];
    int ret1(vector<int>& rating,int i,int prev,int tar){
        if(tar==0){
            return 1;
        }
        if(i==rating.size()){
            return 0;
        }
        if(dp[i][prev+1][tar]!=-1){
            return dp[i][prev+1][tar];
        }
        int ans=0;
        if(tar==3){
            ans+=ret1(rating,i+1,i,tar-1);
        }
        else{
            if(rating[i]>rating[prev]){
                ans+=ret1(rating,i+1,i,tar-1);
            }
        }
        ans+=ret1(rating,i+1,prev,tar);
        return dp[i][prev+1][tar]=ans;
    }
    int ret2(vector<int>& rating,int i,int prev,int tar){
        if(tar==0){
            return 1;
        }
        if(i==rating.size()){
            return 0;
        }
        if(dp[i][prev+1][tar]!=-1){
            return dp[i][prev+1][tar];
        }
        int ans=0;
        if(tar==3){
            ans+=ret2(rating,i+1,i,tar-1);
        }
        else{
            if(rating[i]<rating[prev]){
                ans+=ret2(rating,i+1,i,tar-1);
            }
        }
        ans+=ret2(rating,i+1,prev,tar);
        return dp[i][prev+1][tar]=ans;
    }
    int numTeams(vector<int>& rating) {
        memset(dp,-1,sizeof(dp));
        int a=ret1(rating,0,-1,3);
        memset(dp,-1,sizeof(dp));
        int b=ret2(rating,0,-1,3);
        return a+b;
    }
};