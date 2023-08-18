class Solution {
public:
    bool ret(vector<vector<int>>&adj,int cur,int prevcol,vector<int>&col){
        if(col[cur]!=-1){
            if(prevcol==col[cur]){
                return false;
            }
            return true;
        }
        for(int i=1;i<=4;i++){
            if(i!=prevcol){
                col[cur]=i;
                bool ans=true;
                for(auto it:adj[cur]){
                    ans=ans && ret(adj,it,i,col);    
                }
                if(ans==true){
                    return ans;
                }
            }
            
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]-1].push_back(paths[i][1]-1);
            adj[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                ret(adj,i,-1,col);
            }
        }
        return col;
    }
};