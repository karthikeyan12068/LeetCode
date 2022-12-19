class Solution {
public:
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
        map<int,vector<int>>m1;
        for(int i=0;i<edges.size();i++){
            m1[edges[i][0]].push_back(edges[i][1]);
            m1[edges[i][1]].push_back(edges[i][0]);    
        }
        
        int f=0;
        vector<int>vis(n,0);
        list<int>q;
        q.push_back(source);
        while(!q.empty()){
            int cur=q.front();
            if(cur==destination){
                f=1;
                break;
            }
            q.pop_front();
            vis[cur]=1;
            for(int i=0;i<m1[cur].size();i++){
                if(vis[m1[cur][i]]==0){
                    q.push_back(m1[cur][i]);
                }
            }
        }
        if(f==1){
            return true;
        }
        return false;
    }
};