class Solution {
public:
    int ret(vector<int>& edges,int cur,vector<char>&loop,unordered_map<int,int>&vis,int &edge,int len){
        if(loop[cur]=='b'){
            
            return vis[cur];
        }
        if(loop[cur]=='y'){
            edge=cur;
            return len-vis[cur]+1;
        }
        loop[cur]='y';
        vis[cur]=len;
        int len1=ret(edges,edges[cur],loop,vis,edge,len+1);
        loop[cur]='b';
        if(edge!=-1){
            vis[cur]=len1;
            if(cur==edge){
                edge=-1;
            }
        }
        else{
            vis[cur]=len1+1;
            return len1+1;
        }
        
        return len1;
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        vector<char>vis(edges.size(),'g');
        unordered_map<int,int>m;
        for(int i=0;i<edges.size();i++){
            if(vis[i]=='g'){
                int edge=-1;
                ret(edges,i,vis,m,edge,1);
            }
        }
        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            ans.push_back(m[i]-1);
        }
        return ans;
    }
};