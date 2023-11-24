class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        list<int>l1;
        for(auto it:piles){
            l1.push_back(it);
        }
        int ans=0;
        while(!l1.empty()){
            l1.pop_back();
            ans+=l1.back();
            l1.pop_back();
            l1.pop_front();
        }
        return ans;
    }
};