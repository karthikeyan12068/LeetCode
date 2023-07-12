class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>&G) {
        
        vector<int>outdeg(G.size());
        vector<vector<int>>adj(G.size());
        for(int i=0;i<G.size();i++){
            for(auto it:G[i]){
                
                adj[it].push_back(i);
            }
            outdeg[i]=G[i].size();
        }
        queue<int>q;
        for(int i=0;i<outdeg.size();i++){
            if(outdeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int x=q.size();
            while(x--){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it:adj[node]){
                    outdeg[it]--;
                    if(outdeg[it]==0){
                        q.push(it);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};