class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& rd, vector<vector<int>>& bl) {
        vector<pair<int,int>>adj[n];
        for(auto it:rd){
            adj[it[0]].push_back({it[1],1});
        }
        for(auto it:bl){
            adj[it[0]].push_back({it[1],2});
        }
        vector<vector<int>>ans(n,vector<int>(3,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        ans[0][0]=0;
        while(!q.empty()){
            int dist=q.front().first;
            int curnode=q.front().second.first;
            int curcolor=q.front().second.second;
            q.pop();
            for(auto it:adj[curnode]){
                int newcol=it.second;
                int adjnode=it.first;
                if(curcolor!=newcol && ans[adjnode][newcol]>dist+1){
                    ans[adjnode][newcol]=dist+1;
                    q.push({dist+1,{adjnode,newcol}});
                }
            }
        }
        vector<int>ret(n,INT_MAX);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<3;j++){
                ret[i]=min(ret[i],ans[i][j]);
            }
            if(ret[i]==INT_MAX){
                ret[i]=-1;
            }
        }
        return ret;
    }
};