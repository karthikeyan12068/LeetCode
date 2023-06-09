//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topo(vector<vector<pair<int,int>>>&adj,int node,int val,stack<pair<int,int>>&s,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            topo(adj,it.first,it.second,s,vis);
        }
        s.push({node,val});
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        stack<pair<int,int>>s;
        vector<int>vis(N,-1);
        topo(adj,0,0,s,vis);
        vector<int>dis(N,10e9);
        dis[0]=0;
        while(!s.empty()){
            int node=s.top().first;
            int val=s.top().second;
            s.pop();
            for(auto it:adj[node]){
                int distance=dis[node]+it.second;
                if(distance<dis[it.first]){
                    dis[it.first]=distance;
                }
            }
        }
        for(auto &it:dis){
            if(it==INT_MAX){
                it=-1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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