//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool detect(vector<int> adj[],int node,vector<char>&vis){
        if(vis[node]=='y' || vis[node]=='r'){
            return false;
        }
        if(vis[node]=='g'){
            return true;
        }
        vis[node]='y';
        bool ans=true;
        for(auto it:adj[node]){
            ans=ans&&detect(adj,it,vis);
        }
        if(ans==false){
            vis[node]='r';
        }
        else{
            vis[node]='g';
        }
        return ans;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<char>vis(V,'b');
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(vis[i]=='b'){
                detect(adj,i,vis);
            }
            if(vis[i]=='g'){
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends