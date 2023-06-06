//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool check(int &n,vector<int>&col,vector<int>adj[]){
        queue<pair<pair<int,int>,int>>q;
	    q.push({{-1,n},0});
	    while(!q.empty()){
	        int x=q.size();
	        while(x--){
	            int node=q.front().first.second;
	            int parent=q.front().first.first;
	            int val=q.front().second;
	            q.pop();
	            for(auto it:adj[node]){
	                if(it!=parent){
	                    if(col[it]==-1){
	                        col[it]=!val;
	                        q.push({{node,it},!val});
	                    }
	                    else{
	                        if(val==col[it]){
	                            return false;
	                        }
	                    }
	                }
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>col(V,-1);
	    for(int i=0;i<V;i++){
	        if(col[i]==-1){
	            if(check(i,col,adj)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends