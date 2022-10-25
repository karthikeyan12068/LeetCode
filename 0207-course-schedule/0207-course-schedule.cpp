class Solution {
public:
    bool ret(int val,map<int,vector<int>>&m1,map<int,int>&vis,map<int,int>&vis1){
        if(m1[val].empty() || vis1[val]>0){
            return true;
        }
        if(vis[val]>0){
            return false;
        }
        vis[val]++;
        bool x=true;
        for(auto it:m1[val]){
            x=x&&ret(it,m1,vis,vis1);
            vis[it]=0;
            vis1[it]++;
        }
        return x;
    }
    bool canFinish(int numCourses, vector<vector<int>>& v1) {
        map<int,vector<int>>m1;
        if(v1.empty()){
            return true;
        }
        //sort(v1.begin(),v1.end());
        for(int i=0;i<v1.size();i++){
            m1[v1[i][0]].push_back(v1[i][1]);
        }
        map<int,int>vis1;
        bool x=true;
        for(int i=0;i<v1.size();i++){
            map<int,int>vis;
            if(vis1[v1[i][0]]==0){
                x=x&&ret(v1[i][0],m1,vis,vis1);
                if(x==false){
                    return x;
                }
                
            }
        }
        return x;
    }
};