class Solution {
public:
    int dp[1002][1002];
    int ret(vector<vector<int>>& pairs,int i,int prev){
        if(i==pairs.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take=0,ntake=0;
        if(prev==-1){
            take=1+ret(pairs,i+1,i);
        }
        else{
            if(pairs[i][0]>pairs[prev][1]){
                take=1+ret(pairs,i+1,i);
            }
        }
        ntake=0+ret(pairs,i+1,prev);
        return dp[i][prev+1]=max(take,ntake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        return ret(pairs,0,-1);
    }
};