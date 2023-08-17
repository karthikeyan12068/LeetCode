class Solution {
public:
    int ret(vector<vector<int>>&adj,int cur,int parent,vector<int>&vis){
        vis[cur]=1;
        int ans=0;
        for(auto it:adj[cur]){
            if(it!=parent && vis[it]==-1){
                ans+=1+ret(adj,it,cur,vis);
            }
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>>adj(stones.size());
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(stones.size(),-1);
        int ans=0;
        for(int i=0;i<stones.size();i++){
            if(vis[i]==-1){
                ans+=ret(adj,i,-1,vis);
            }
        }
        return ans;
    }
};