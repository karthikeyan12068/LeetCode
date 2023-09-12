class Solution {
public:
    int dp[30001][2];
    int ret(vector<int>& prices,int i,int c){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][c]!=-1){
            return dp[i][c];
        }
        int pos1=INT_MIN,pos2=INT_MIN;
        if(c==0){
            pos1=-prices[i]+ret(prices,i+1,1);
            pos2=0+ret(prices,i+1,0);
        }
        else{
            pos1=prices[i]+ret(prices,i+1,0);
            pos2=0+ret(prices,i+1,1);
        }
        return dp[i][c]=max(pos1,pos2);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return ret(prices,0,0);
    }
};