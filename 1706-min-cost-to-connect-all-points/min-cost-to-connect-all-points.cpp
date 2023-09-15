class DSU{
    vector<long long int>parent,size;
public:
    DSU(long long int n){
        parent.resize(n);
        size.resize(n,1);
        for(long long int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    long long int fup(long long int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=fup(parent[u]);
    }
    void combine(long long int u,long long int v){
        long long int u1=fup(u);
        long long int v1=fup(v);
        if(u1==v1){
            return;
        }
        if(size[v1]>size[u1]){
            parent[u1]=v1;
            size[v1]+=size[u1];
        }
        else{
            parent[v1]=u1;
            size[u1]+=size[v1];
        }
    }
};
class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<long long int,pair<long long int,long long int>>>v;
        for(long long int i=0;i<points.size();i++){
            for(long long int j=i+1;j<points.size();j++){
                v.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
            }
        }
        sort(v.begin(),v.end());
        DSU d1(points.size());
        long long int ans=0;
        for(long long int i=0;i<v.size();i++){
            
            long long int u1=d1.fup(v[i].second.first);
            long long int v1=d1.fup(v[i].second.second);
            if(u1!=v1){
                d1.combine(u1,v1);
                ans+=v[i].first;
            }
            
        }
        return ans;
    }
};