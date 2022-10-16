class Solution {
public:
    int help(int n,map<int,int>&m){
        if(n<=1){
            m[n]=-1;
            return 0;
        }
        if(m[n]==-1){
            return 0;
        }
        if(m[n]==1){
            return 1;
        }
        for(int i=1;i<n;i++){
            if(n%i==0){
                if(help(n-i,m)==0){
                    m[n]=1;
                    return 1;
                }
            }
        }
        m[n]=-1;
        return 0;
        
    }
    bool divisorGame(int n) {
        map<int,int>m1;
        return help(n,m1);
    }
};