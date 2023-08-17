class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>adj(n);
        map<int,int>r;
        for(auto it:restricted){
            r[it]++;
        }
        for(int i=0;i<edges.size();i++){
            if(r[edges[i][0]]>0 || r[edges[i][1]]>0){
                continue;
            }
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int s=0;
        for(auto it:adj){
            cout<<s<<"->";
            for(auto it1:it){
                cout<<it1<<' ';
            }
            cout<<'\n';
            s++;
        }
        vector<int>vis(n,-1);
        int ans=0;
        for(int i=0;i<=0;i++){
            if(r[i]==0 && vis[i]==-1){
                queue<int>q;
                q.push(i);
                int temp=1;
                vis[i]=1;
                while(!q.empty()){
                    int x=q.size();
                    while(x--){
                        int node=q.front();
                        q.pop();
                        vis[node]=1;
                        for(auto it:adj[node]){
                            if(vis[it]==-1){
                                vis[it]=1;
                                q.push(it);
                                temp++;
                            }
                        }
                    }
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};