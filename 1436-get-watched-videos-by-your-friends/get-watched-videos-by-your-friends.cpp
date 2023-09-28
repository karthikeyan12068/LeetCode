class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int l=0;
        queue<int>q;
        q.push(id);
        map<string,int>m;
        vector<int>vis(watchedVideos.size(),-1);
        vis[id]=1;
        vector<pair<int,string>>ans;
        while(!q.empty()){
            if(level==l){
                int x=q.size();
                while(x--){
                    int node=q.front();
                    
                    q.pop();
                    for(auto it:watchedVideos[node]){
                        
                        m[it]++;
                    }
                }
                for(auto it:m){
                    ans.push_back({it.second,it.first});
                }
                sort(ans.begin(),ans.end());
                vector<string>ret;
                for(auto it:ans){
                    ret.push_back(it.second);
                }
                return ret;
            }
            else{
                int x=q.size();
                while(x--){
                    int node=q.front();
                    
                    q.pop();
                    for(auto it:friends[node]){
                        if(vis[it]==-1){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
            }
            l++;
        }
        return {};
    }
};