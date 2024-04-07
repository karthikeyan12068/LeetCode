class Solution {
public:
    int dp[101][101];
    bool ret(string &s,int i,int op){
        if(i==s.length()){
            //cout<<op<<'\n';
            if(op==0){
                return true;
            }
            return false;
        }
        if(dp[i][op]!=-1){
            if(dp[i][op]==0){
                return true;
            }
            return false;
        }
        bool ans=false;
        if(s[i]=='('){
            ans=ret(s,i+1,op+1);
        }else{
            if(s[i]==')'){
                if(op==0){
                    return false;
                }
                ans=ret(s,i+1,op-1);
            }else{
                if(s[i]=='*'){
                    ans=ret(s,i+1,op+1)|ret(s,i+1,op);
                    if(op>0){
                        ans=ans|ret(s,i+1,op-1);
                    }
                }
            }
        }
        if(ans==true){
            dp[i][op]=0;
        }else{
            dp[i][op]=1;
        }
        return ans;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return ret(s,0,0);
    }
};