class Solution {
public:
    int n1;
    void ret(int i,vector<int>&nodes,vector<int>&ans,map<int,vector<vector<int>>>&dis,vector<vector<int>>&shd){
        if(i==n1){
            if(nodes.size()<=1){
                return;
            }
            set<int>s;
            int ans1=0;
            
            for(int j=0;j<nodes.size();j++){
                for(int k=j+1;k<nodes.size();k++){
                    for(auto it:dis[nodes[j]][nodes[k]]){
                        s.insert(it);
                    }
                    ans1=max(ans1,shd[nodes[j]][nodes[k]]);
                }
            }
            if(s.size()==nodes.size()){
                ans[ans1-1]++;
            }
            return;
        }
        nodes.push_back(i);
        ret(i+1,nodes,ans,dis,shd);
        nodes.pop_back();
        ret(i+1,nodes,ans,dis,shd);
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        n1=n;
        
        vector<vector<int>>cost(n,vector<int>(n,1e9));
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            cost[edges[i][0]-1][edges[i][1]-1]=1;
            cost[edges[i][1]-1][edges[i][0]-1]=1;
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
            adj[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        map<int,vector<vector<int>>>m;
        for(int i=0;i<n;i++){
            vector<vector<int>>v(n);
            for(int j=0;j<n;j++){
                if(i==j){
                    cost[i][j]=0;
                }
            }
            v[i]={};
            vector<int>vis(n,-1);
            vis[i]=1;
            queue<vector<int>>q;
            q.push({i});
            vis[i]=1;
            while(!q.empty()){
                int x=q.size();
                while(x--){
                    auto node=q.front();
                    q.pop();
                    if(node.size()>1){
                        v[node.back()]=node;
                    }
                    for(auto it:adj[node.back()]){
                        if(vis[it]==-1){
                            vis[it]=1;
                            node.push_back(it);
                            q.push(node);
                            node.pop_back();
                        }
                    }    
                }
            }
            m[i]=v;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        
        vector<int>ans1(n-1);
        vector<int>nodes;
        ret(0,nodes,ans1,m,cost);
        return ans1;
    }
};