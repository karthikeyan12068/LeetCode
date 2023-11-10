class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>&v) {
        map<int,vector<int>>m;
        for(int i=0;i<v.size();i++){
            m[v[i][0]].push_back(v[i][1]);
            m[v[i][1]].push_back(v[i][0]);
        }
        queue<int>q;
        list<int>ans;
        ans.push_back(v[0][0]);
        q.push(v[0][0]);
        map<int,int>vis;
        vis[v[0][0]]++;
        while(!q.empty()){
            int x=q.size();
            while(x--){
                int node=q.front();
                q.pop();
                int l=INT_MAX,r=INT_MAX;
                if(m[node].size()==2){
                    l=m[node][0];
                    r=m[node][1];
                }
                else{
                    l=m[node][0];
                }
                if(l!=INT_MAX && vis[l]==0){
                    vis[l]++;
                    if(ans.front()==node){
                        ans.push_front(l);
                    }
                    else{
                        ans.push_back(l);
                    }
                    q.push(l);
                }
                if(r!=INT_MAX && vis[r]==0){
                    vis[r]++;
                    if(ans.front()==node){
                        ans.push_front(r);
                    }
                    else{
                        ans.push_back(r);
                    }
                    q.push(r);
                }
            }
        }
        vector<int>t;
        for(auto it:ans){
            t.push_back(it);
        }
        return t;
    }
};