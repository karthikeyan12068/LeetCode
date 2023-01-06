class Solution {
public:
   
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue <int, vector<int>, greater<>> pq;
        for(int i=0;i<costs.size();i++){
            pq.push(costs[i]);
        }
        int c=0;
        while(true){
            if(coins-pq.top()<0 || pq.empty()){
                break;
            }
            c++;
            coins-=pq.top();
            pq.pop();
            if(coins<=0){
                break;
            }
        }
        return c;
    }
};