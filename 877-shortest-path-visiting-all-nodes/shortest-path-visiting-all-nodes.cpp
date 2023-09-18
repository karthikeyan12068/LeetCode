class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int,pair<int,int>>>q;
        int cmp=(1<<graph.size())-1;
        set<pair<int,int>>vis;
        for(int i=0;i<graph.size();i++){
            int bit=0;
            bit=bit^(1<<i);
            q.push({i,{0,bit}});
            vis.insert({i,bit});
        }
        
        while(!q.empty()){
            int x=q.size();
            while(x--){
                int cur=q.front().first;
                int dis=q.front().second.first;
                int mask=q.front().second.second;
                q.pop();
                
                for(auto it:graph[cur]){
                    int newmask=(mask|(1<<it));
                    if(newmask==cmp){
                        return dis+1;
                    }
                    if(vis.count({it,newmask})){
                        continue;
                    }
                    q.push({it,{dis+1,newmask}});
                    vis.insert({it,newmask});
                }
            }
        }
        return 0;
    }
};