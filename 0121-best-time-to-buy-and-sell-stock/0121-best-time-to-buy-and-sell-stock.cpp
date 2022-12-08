class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start=-1,ans=0;
        for(int i=prices.size()-1;i>=0;i--){
            if(i==prices.size()-1){
                start=prices[i];
            }
            else{
                if(prices[i]>start){
                    start=prices[i];
                }else{
                    ans=max(ans,start-prices[i]);
                }
            }
        }
        return ans;
    }
};