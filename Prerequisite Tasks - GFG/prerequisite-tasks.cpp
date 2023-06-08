//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool approach1(vector<vector<int>>&adj,int cur,vector<char>&vis){
        if(vis[cur]=='y' || vis[cur]=='r'){
            return false;
        }
        if(vis[cur]=='g'){
            return true;
        }
        vis[cur]='y';
        bool ans=true;
        for(auto it:adj[cur]){
            ans=ans && approach1(adj,it,vis);
        }
        if(ans==false){
            vis[cur]='r';
        }
        else{
            vis[cur]='g';
        }
        return ans;
    }
    bool approach2(vector<vector<int>>&adj,int cur,vector<int>&vis){
        if(vis[cur]!=-1 || vis[cur]==0){
            return false;
        }
        vis[cur]=1;
        bool ans=true;
        for(auto it:adj[cur]){
            ans=ans && approach2(adj,it,vis);
        }
        if(ans==false){
            vis[cur]=0;
        }
        return ans;
    }
    bool approach3(vector<vector<int>>&adj,int N){
        vector<int>indeg(N);
        for(int i=0;i<N;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<N;i++){
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
        if(ans.size()!=N){
            return false;
        }
        return true;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>>adj(N);
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    vector<char>vis1(N,'b');
	    for(int i=0;i<N;i++){
	        if(vis1[i]=='b'){
	            bool ans=approach1(adj,i,vis1);
	            if(ans==false){
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
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends