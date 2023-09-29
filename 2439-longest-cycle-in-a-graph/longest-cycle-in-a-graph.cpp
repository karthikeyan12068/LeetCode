class Solution {
public:
    int ret(vector<int>& edges,int cur,vector<char>&vis,int &edge,int &ans){
        if(cur==-1 || vis[cur]=='b'){
            return -1e9;
        }
        
        if(vis[cur]=='y'){
            edge=cur;
            return 0;
        }
        vis[cur]='y';
        int check=1+ret(edges,edges[cur],vis,edge,ans);
        if(edge==cur){
            ans=max(ans,check);
            check=-1e9;
            edge=-1;
        }
        vis[cur]='b';
        return check;
    }
    int longestCycle(vector<int>& edges) {
        int ans=-1;
        vector<char>vis(edges.size(),'g');
        for(int i=0;i<edges.size();i++){
            if(vis[i]=='g'){
                int c=-1;
                ret(edges,i,vis,c,ans);
            }
        }
        return ans;
    }
};