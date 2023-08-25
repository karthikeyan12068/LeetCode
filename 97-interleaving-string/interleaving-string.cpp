class Solution {
public:
    int dp[102][102][202];
    bool ret(string &s1, string &s2, string &s3,int i,int j,int k){
        if(k==s3.length()){
            if(i==s1.length() && j==s2.length()){
                return true;
            }
            return false;
        }
        if(i==s1.length() && j==s2.length()){
            return false;
        }
        if(dp[i][j][k]!=-1){
            if(dp[i][j][k]==0){
                return true;
            }
            return false;
        }
        bool ans=false;
        if(s1[i]!=s3[k] && s2[j]!=s3[k]){
            ans=false;
        }
        else{
            if(i<s1.length() && j<s2.length()){
                if(s1[i]==s3[k] && s2[j]==s3[k]){
                    ans=ans|ret(s1,s2,s3,i+1,j,k+1)|ret(s1,s2,s3,i,j+1,k+1);
                }
                else{
                    if(s1[i]==s3[k]){
                        ans=ans|ret(s1,s2,s3,i+1,j,k+1);
                    }
                    else{
                        ans=ans|ret(s1,s2,s3,i,j+1,k+1);
                    }
                }
            }
            else{
                if(i<s1.length()){
                    if(s1[i]!=s3[k]){
                        return false;
                    }
                    else{
                        ans=ans|ret(s1,s2,s3,i+1,j,k+1);
                    }
                }
                else{
                    if(s2[j]!=s3[k]){
                        return false;
                    }
                    else{
                        ans=ans|ret(s1,s2,s3,i,j+1,k+1);
                    }
                }
            }
        }
        if(ans==true){
            dp[i][j][k]=0;
        }
        else{
            dp[i][j][k]=1;
        }
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return ret(s1,s2,s3,0,0,0);
    }
};