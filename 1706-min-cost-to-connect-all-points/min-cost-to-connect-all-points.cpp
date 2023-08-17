class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>>adj(points.size());
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                adj[i].push_back({j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
                adj[j].push_back({i,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>q;
        q.push({0,{0,-1}});
        vector<int>vis(points.size(),-1);
        int sum=0;
        while(!q.empty()){
            auto node=q.top();
            q.pop();
            if(vis[node.second.first]==-1){
                vis[node.second.first]=1;
                sum+=node.first;
                for(auto it:adj[node.second.first]){
                    if(it.first!=node.second.second && vis[it.first]==-1){
                        q.push({it.second,{it.first,node.second.first}});
                    }
                }
            }
        }
        return sum;
    }
};