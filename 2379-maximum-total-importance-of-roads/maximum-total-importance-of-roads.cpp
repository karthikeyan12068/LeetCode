class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long sum=0;
        vector<vector<int>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
        for(int i=0;i<n;i++){
            q.push({adj[i].size(),i});
        }
        vector<int>asig(n);
        int st=1;
        while(!q.empty()){
            auto node=q.top();
            q.pop();
            asig[node.second]=st;
            st++;
        }
        for(auto it:roads){
            sum+=asig[it[0]]+asig[it[1]];
        }
        return sum;
    }
};