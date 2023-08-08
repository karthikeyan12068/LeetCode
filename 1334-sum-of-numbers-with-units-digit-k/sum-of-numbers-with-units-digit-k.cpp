class Solution {
public:
    int dp[3005];
    int ret(int tar,int &k){
        if(tar<0){
            return 3001;
        }
        if(tar==0){
            return 0;
        }
        if(dp[tar]!=-1){
            return dp[tar];
        }
        int ans=3001;
        int start=k,c=0;
        while(start+c<=tar){
            ans=min(ans,1+ret(tar-(start+c),k));
            c+=10;
        }
        return dp[tar]=ans;
    }
    int minimumNumbers(int num, int k) {
        if(num==0){
            return 0;
        }
        if(k==0){
            if(num%10!=0){
                return -1;
            }
            return 1;
            //return ans;
        }
        memset(dp,-1,sizeof(dp));
        int ans=ret(num,k);
        if(ans==3001){
            return -1;
        }
        return ans;
    }
};