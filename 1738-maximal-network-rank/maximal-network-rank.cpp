class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        vector<set<int>>values(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
            values[roads[i][0]].insert(roads[i][1]);
            values[roads[i][1]].insert(roads[i][0]);
        }
        vector<int>deg(n);
        
        for(int i=0;i<n;i++){
            deg[i]=adj[i].size();
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int it=i+1;it<n;it++){
                auto it1=values[i].lower_bound(it);
                if(it1!=values[i].end() && *it1==it){
                    ans=max(ans,(deg[i]+deg[it])-1);
                }
                else{
                    ans=max(ans,(deg[i]+deg[it]));
                }
            }
        }
        return ans;
    }
};