class Solution {
public:
// -1 not processed 0 in process 1 processed and good 2 processed and not good
    int ret(vector<vector<int>>&adj,int cur,int parent,vector<int>&vis){
        if(vis[cur]==0){
            return cur;
        }
        if(vis[cur]==1 || vis[cur]==2){
            return -1;
        }
        vis[cur]=0;
        int ans1=-1;
        for(auto it:adj[cur]){
            if(it!=parent){
                int ans=ret(adj,it,cur,vis);
                if(ans!=-1 && ans1!=cur){
                    ans1=ans;
                    
                }
            }
        }
        
        if(ans1==-1){
            vis[cur]=1;
        }
        else{
            if(ans1!=cur){
                vis[cur]=2;
                return ans1;
            }
            else{
                if(ans1==cur){
                    vis[cur]=2;
                    return -1;
                }
            }
        }
        return -1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=-1;
        for(auto it:edges){
            n=max(n,max(it[0],it[1]));
        }
        vector<int>vis(n+1,-1);
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int node=ret(adj,1,-1,vis);
        vector<int>v;
        for(auto it:edges){
            if(vis[it[0]]==2 && vis[it[1]]==2){
                v=it;
            }
        }
        return v;
    }
};