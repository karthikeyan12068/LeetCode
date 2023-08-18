class DisjointSet{
public:
    vector<int>parent,size;
    DisjointSet(){
        parent.resize(27);
        size.resize(27);
        for(int i=0;i<27;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int fup(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=fup(parent[u]);
    }
    void combine(int u,int v){
        int ulp_u=fup(u);
        int ulp_v=fup(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet dj;
        vector<vector<int>>adj(27);
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){
                for(auto it:adj[equations[i][0]-'a']){
                    if(it==equations[i][3]-'a'){
                        return false;
                    }
                    int ulp=dj.fup(it);
                    if(ulp==dj.fup(equations[i][3]-'a')){
                        return false;
                    }
                }
                for(auto it:adj[equations[i][3]-'a']){
                    if(it==equations[i][0]-'a'){
                        return false;
                    }
                    int ulp=dj.fup(it);
                    if(ulp==dj.fup(equations[i][0]-'a')){
                        return false;
                    }
                }
                dj.combine(equations[i][0]-'a',equations[i][3]-'a');
            }
            else{
                int ulp_u=dj.fup(equations[i][0]-'a');
                int ulp_v=dj.fup(equations[i][3]-'a');
                if(ulp_u==ulp_v){
                    return false;
                }
                adj[equations[i][0]-'a'].push_back(equations[i][3]-'a');
                adj[equations[i][3]-'a'].push_back(equations[i][0]-'a');
            }
        }
        return true;
    }
};