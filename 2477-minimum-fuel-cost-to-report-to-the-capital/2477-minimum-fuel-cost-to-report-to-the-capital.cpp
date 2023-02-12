class Solution {
public:
    int ret(unordered_map<int,vector<int>>&adj,int curnode,int parent,int seats,long long &ans){
        int sum=1;
        for(auto it:adj[curnode]){
            if(it==parent){
                continue;
            }
            sum+=ret(adj,it,curnode,seats,ans);
        }
        if(curnode!=0){
            ans+=sum/seats+(sum%seats>0);
        }
        return sum;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int,vector<int>>adj;
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long ans=0;
        ret(adj,0,-1,seats,ans);
        return ans;
    }
};