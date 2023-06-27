//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        //dis,node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
        q.push({0,1});
        vector<int>parent(n+1);
        vector<int>dis(n+1,INT_MAX);
        dis[1]=0;
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        while(!q.empty()){
            auto node=q.top();
            q.pop();
            for(auto it:adj[node.second]){
                if(node.first+it.second<dis[it.first]){
                    parent[it.first]=node.second;
                    dis[it.first]=node.first+it.second;
                    if(it.first!=n){
                        q.push({dis[it.first],it.first});
                    }
                }
            }
        }
        /*for(int i=1;i<=n;i++){
            cout<<parent[i]<<" "<<dis[i]<<'\n';
        }*/
        vector<int>ans;
        ans.push_back(n);
        int st=n;
        if(dis[n]==INT_MAX){
            return {-1};
        }
        while(st!=1){
            ans.push_back(parent[st]);
            st=parent[st];
        }
        //ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends