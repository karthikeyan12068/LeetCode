class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        map<int,set<int>>adj;
        for(int i=0;i<routes.size();i++){
            for(auto it:routes[i]){
                adj[it].insert(i);
            }
        }
        queue<pair<int,int>>q;
        map<int,int>vis;
        vector<int>t;
        
        for(auto &it:adj[source]){
            t.push_back(it);
            for(auto &it1:routes[it]){
                q.push({it1,1});
                
            }
            vis[it]++;
            //cout<<it<<' ';
        }
        for(auto &it:t){
            for(auto &it1:routes[it]){
                q.push({it1,1});
                adj[it1].erase(it);
            }
            vis[it]++;
        }
        t.clear();
        while(!q.empty()){
            int x=q.size();
            while(x--){
                auto cur=q.front();
                if(cur.first==target){
                    return cur.second;
                }
                q.pop();
                for(auto &it:adj[cur.first]){
                    if(vis[it]==0){
                        t.push_back(it);
                    }
                }
                if(!t.empty()){
                    for(auto &it:t){
                        for(auto &it1:routes[it]){
                            q.push({it1,cur.second+1});
                            adj[it1].erase(it);
                        }
                        vis[it]++;
                    }
                    t.clear();
                }
            }
        }
        return -1;
    }
};