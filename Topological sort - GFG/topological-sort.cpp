//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void ret(vector<int> adj[],int node,vector<int>&vis,stack<int>&s){
	    if(vis[node]!=-1){
	        return;
	    }
	    vis[node]=1;
	    for(auto it:adj[node]){
	        ret(adj,it,vis,s);
	    }
	    s.push(node);
	}
	void khan_algo(int V, vector<int> adj[],vector<int>&ans){
	    queue<int>q;
	    vector<int>indeg(V);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indeg[it]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int x=q.size();
	        while(x--){
	            int node=q.front();
	            q.pop();
	            ans.push_back(node);
	            for(auto it:adj[node]){
	                indeg[it]--;
	                if(indeg[it]==0){
	                    q.push(it);
	                }
	            }
	        }
	    }
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    /*vector<int>vis(V,-1),ans;
	    stack<int>s;
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            ret(adj,i,vis,s);
	        }
	    }
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;*/
	    vector<int>ans;
	    khan_algo(V,adj,ans);
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends