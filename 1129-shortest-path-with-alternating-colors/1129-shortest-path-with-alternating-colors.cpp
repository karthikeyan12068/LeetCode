class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //Colour Code for Red is 1 and for Blue is 2
        //Colour 0 indicates no colour
        vector<pair<int,int>> adj[n];
        for(auto &i:redEdges){
            int u=i[0],v=i[1];
            adj[u].push_back({v,1});
        }
        for(auto &i:blueEdges){
            int u=i[0],v=i[1];
            adj[u].push_back({v,2});
        }
        vector<vector<int>> dist(n,vector<int>(3,INT_MAX));/* dist[i][j] denotes minimum distance to reach node i with prev edge coloured as j */
        dist[0][0]=0;
        queue<pair<int,pair<int,int>>> pq;//{distance,{node,colour}}
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int dis=pq.front().first;
            int currNode=pq.front().second.first;
            int colour=pq.front().second.second;
            pq.pop();
            for(auto &i:adj[currNode]){
                int adjNode=i.first;
                int newColour=i.second;
                if(colour != newColour and dist[adjNode][newColour]>dis+1){
                    dist[adjNode][newColour]=dis+1;
                    pq.push({dis+1,{adjNode,newColour}});
                }
            }
        }
        vector<int> res(n,INT_MAX);
        for(int i=0;i<n;i++){
            int dis=min(dist[i][0],min(dist[i][1],dist[i][2]));
            res[i]=(dis==INT_MAX)?-1:dis;
        }
        return res;
    }
};