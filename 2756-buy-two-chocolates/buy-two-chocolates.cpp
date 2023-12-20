class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int rem=money-(prices[0]+prices[1]);
        if(rem>=0){
            return rem;
        }
        return money;
    }
};