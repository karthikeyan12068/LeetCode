class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
       priority_queue<long long>q;
       priority_queue<long long,vector<long long>,greater<>>q1;
       for(long long i=1;i<weights.size();i++){
           q.push(weights[i]+weights[i-1]);
           q1.push(weights[i]+weights[i-1]);
       } 
       k--;
       long long sum1=weights[0]+weights[weights.size()-1];
       long long sum2=weights[0]+weights[weights.size()-1];
       while(k--){
           sum1+=q.top();
           sum2+=q1.top();
           q.pop();
           q1.pop();
       }
       return abs(sum1-sum2);
    }
};