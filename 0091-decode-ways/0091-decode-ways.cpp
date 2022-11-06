class Solution {
public:
    int str_to_in(string s)
    {
        stringstream geek(s);
        int x = 0;
        geek >> x;
        return x;
    }
    int ret(int i,string s,vector<int>&dp){
        if(i==s.length()){
            return 1;
        }
        if(i>s.length()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int right=0,left=0;
        if(s[i]!='0' && s[i]-'0'!=0){
            left=ret(i+1,s,dp);
        }
        if(s[i]!='0' && i+2<=s.length()){
            string s1="";
            s1+=s[i];
            s1+=s[i+1];
            int x=str_to_in(s1);
            if(x<=26){
                right=ret(i+2,s,dp);
            }
        }
        return dp[i]=right+left;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        return ret(0,s,dp);
    }
};