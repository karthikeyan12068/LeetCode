class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>m;
        for(auto it:tasks){
            m[it]++;
        }
        priority_queue<int>pq;
        for(auto it:m){
            pq.push(it.second);
        }
        int ans=0;
        while(!pq.empty()){
            int time=0;
            vector<int>tmp;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top()-1);
                    time++;
                    pq.pop();
                }
            }
            for(auto it:tmp){
                if(it>0){
                    pq.push(it);
                }
            }
            if(!pq.empty()){
                ans+=n+1;
            }
            else{
                ans+=time;
            }
        }
        return ans;
    }
};