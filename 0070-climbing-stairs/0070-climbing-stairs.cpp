class Solution {
public:
    int ret(int i,int n,vector<int>&v1){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(v1[i]!=-1){
            return v1[i];
        }
        int o=ret(i+1,n,v1);
        int t=ret(i+2,n,v1);
        return v1[i]=o+t;
    }
    int climbStairs(int n) {
        vector<int>v1(n+1,-1);
        return ret(0,n,v1);
    }
};