//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<int>vis(V+1,0);
        vis[0]=-1;
        queue<int>q;
        int tot_com=0,conn=0;
        vector<int>con(V+1,-1);
        for(int i=1;i<=V;i++){
            if(adj[i].size()!=0 && vis[i]==0){
                q.push(i);
                int tot_comp=0;
                while(!q.empty()){
                    int t=q.size();
                    while(t--){
                        int x=q.front();
                        q.pop();
                        if(vis[x]==0){
                            tot_comp++;
                            vis[x]+=2;
                            for(auto it:adj[x]){
                                if(vis[it]!=0){
                                    vis[it]++;
                                    continue;
                                }
                                q.push(it);
                            }
                        }
                        else{
                            vis[x]++;
                        }
                    }
                }
                vis[i]--;
                con[i]=tot_comp;
            }
        }
        /*for(auto it:con){
            cout<<it<<" ";
        }
        cout<<'\n';
        for(auto it:vis){
            cout<<it<<" ";
        }
        cout<<'\n';*/
        for(int i=1;i<=V;i++){
            if(con[i]>-1){
                //cout<<i<<"\n";
                int f=0;
                q.push(i);
                while(!q.empty()){
                    int t=q.size();
                    while(t--){
                        int x=q.front();
                        q.pop();
                        if(vis[x]!=con[i]){
                            f=1;
                            break;
                        }
                        else{
                            for(auto it:adj[x]){
                                if(con[it]==-1){
                                    q.push(it);
                                    con[it]--;
                                }
                            }
                        }
                    }
                }
                if(f==0){
                    //cout<<i<<"\n";
                    conn++;
                }
            }
            else{
                if(vis[i]==0 && con[i]<=-1){
                    conn++;
                }
            }
        }
        return conn;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends