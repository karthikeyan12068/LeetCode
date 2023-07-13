class Solution {
public:
    bool ret(vector<vector<int>>&adj,vector<char>&col,int cur){
        if(col[cur]=='r' || col[cur]=='y'){
            return false;
        }
        if(col[cur]=='g'){
            return true;
        }
        col[cur]='y';
        bool ans=true;
        for(auto it:adj[cur]){
            ans=ans&ret(adj,col,it);
        }
        if(ans==false){
            col[cur]='r';
        }
        else{
            col[cur]='g';
        }
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<char>col(numCourses,'b');
        for(int i=0;i<numCourses;i++){
            if(col[i]=='b'){
                if(ret(adj,col,i)){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};