class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>count;
        unordered_map<int,priority_queue<pair<int,int>>>m;
        for(int i=0;i<tasks.size();i++){
            count[tasks[i]]++;
        }

        for(auto it:count){
            m[1].push({it.second,it.first});
        }
        
        int st=1;
        
        while(!count.empty()){
            
            if(m[st].empty()){
                st++;
            }
            else{
                auto val=m[st].top();
                m[st].pop();
                count[val.second]--;
                if(count[val.second]==0){
                    count.erase(val.second);
                    if(count.empty()){
                        return st;
                    }
                }
                else{
                    m[st+n+1].push({val.first-1,val.second});
                }
                while(!m[st].empty()){
                    m[st+1].push({m[st].top().first,m[st].top().second});
                    m[st].pop();
                }
                st++;
            }
        }
        return st;
    }
};