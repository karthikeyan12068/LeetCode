class Solution {
public:
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            queue<int>q;
            q.push(i);
            vector<int>vis(n,-1);
            vis[i]=1;
            set<int>temp;
            while(!q.empty()){
                int x=q.size();
                while(x--){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(vis[it]==-1){
                            vis[it]=1;
                            temp.insert(it);
                            q.push(it);
                        }
                    }
                }
            }
            for(auto it:temp){
                ans[i].push_back(it);
            }
        }
        return ans;
    }
};