class Solution {
public:
    int ret(vector<vector<int>>&adj,int cur,int n){
        vector<int>vis(n,-1);
        queue<pair<int,int>>q;
        q.push({cur,-1});
        vis[cur]=0;
        int ans=1e9;
        while(!q.empty()){
            int x=q.size();
            while(x--){
                auto node=q.front();
                q.pop();
                for(auto it:adj[node.first]){
                    if(it!=node.second){
                        if(vis[it]!=-1){
                            ans=min(ans,vis[it]+vis[node.first]+1);
                        }
                        else{
                            vis[it]=vis[node.first]+1;
                            q.push({it,node.first});
                        }
                    }
                }
            }
        }
        return ans;
    }
    int findShortestCycle(int n, vector<vector<int>>& mat) {
        vector<vector<int>>adj(n);
        for(int i=0;i<mat.size();i++){
            adj[mat[i][0]].push_back(mat[i][1]);
            adj[mat[i][1]].push_back(mat[i][0]);
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,ret(adj,i,n));
        }
        return (ans==1e9)?-1:ans;
    }
};