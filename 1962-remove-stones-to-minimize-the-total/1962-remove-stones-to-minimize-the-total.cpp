class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;
        int sum=0;
        for(auto it:piles){
            q.push(it);
            sum+=it;
        }
        while(k--){
            int x=q.top();
            sum-=x;
            x-=x/2;
            sum+=x;
            q.pop();
            q.push(x);
        }
        return sum;
    }
};