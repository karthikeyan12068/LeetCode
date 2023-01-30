class Solution {
public:
    vector<int> ret(int i,string &labels,vector<vector<int>>&adj,vector<int>&ans){
        vector<int>temp(26,0);
        temp[labels[i]-'a']=1;
        ans[i]=1;
        for(int j=0;j<adj[i].size();j++){
            if(!ans[adj[i][j]]){
                vector<int>c=ret(adj[i][j],labels,adj,ans);
                for(int k=0;k<26;k++){
                    temp[k]+=c[k];
                }
            }
        }
        ans[i]=temp[labels[i]-'a'];
        return temp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>ans(n,0);
        ret(0,labels,adj,ans);
        return ans;
    }
};