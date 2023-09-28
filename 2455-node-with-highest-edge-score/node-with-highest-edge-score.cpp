class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<long long int,long long int>m;
        for(long long int i=0;i<edges.size();i++){
            m[edges[i]]+=i;
        }
        long long int ans=-1,val=-1;
        for(auto it:m){
            
            if(it.second>ans){
                ans=it.second;
                val=it.first;
            }
        }
        return val;
    }
};