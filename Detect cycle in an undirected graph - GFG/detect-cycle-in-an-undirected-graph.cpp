//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool detect(vector<int>adj[],vector<int>&vis,int &cur){
        queue<pair<int,int>>q;
        q.push({cur,-1});
        while(!q.empty()){
            int x=q.size();
            while(x--){
                auto node=q.front();
                q.pop();
                for(auto it:adj[node.first]){
                    if(it!=node.second && vis[it]==0){
                        vis[it]=1;
                        q.push({it,node.first});
                    }
                    else{
                        if(vis[it]==1 && it!=node.second){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                vis[i]=1;
                if(detect(adj,vis,i)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends