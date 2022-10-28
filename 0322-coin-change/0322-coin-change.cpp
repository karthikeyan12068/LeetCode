class Solution {
public:
    int ret(int i,vector<int>& c, int a,vector<vector<int>>&v1){
        if(a==0){
            return 0;
        }
        if(i==c.size() || a<0){
            return INT_MAX-1;
        }
        if(v1[i][a]!=-1){
            return v1[i][a];
        }
        int take=1+ret(i,c,a-c[i],v1);
        int notake=0+ret(i+1,c,a,v1);
        //cout<<i<<" "<<a<<" "<<take<<" "<<notake<<"\n";
        return v1[i][a]=min(take,notake);
    }
    int coinChange(vector<int>& c, int a) {
        vector<vector<int>>v1(c.size());
        for(int i=0;i<c.size();i++){
            for(int j=0;j<=a;j++){
                v1[i].push_back(-1);
            }
        }
        int a1=ret(0,c,a,v1);
        if(a1<2147483646){
            return a1;
        }
        return -1;
    }
};