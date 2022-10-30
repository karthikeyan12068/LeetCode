class Solution {
public:
    bool ret(int cur,int x,int y,int z,int t,vector<int>&vis){
        if(cur==t){
            return true;
        }
        if(vis[cur]!=0){
            return false;
        }
        vis[cur]=1;
        bool x1=false,x2=false,x3=false,x4=false;
        if(cur+x<=z){
            x1=ret(cur+x,x,y,z,t,vis);
        }
        if(cur-x>=0){
            x2=ret(cur-x,x,y,z,t,vis);
        }
        if(cur+y<=z){
            x3=ret(cur+y,x,y,z,t,vis);
        }
        if(cur-y>=0){
            x4=ret(cur-y,x,y,z,t,vis);
        }
        return x1||x2||x3||x4;
    }
    bool canMeasureWater(int x, int y, int t) {
        int z=x+y;
        vector<int>vis(z+1,0);
        return ret(0,x,y,x+y,t,vis);
    }
};