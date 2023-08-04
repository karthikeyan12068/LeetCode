class Solution {
public:
    bool ret(string &s,int i,map<string,int>&m,vector<int>&dp){
        if(i>=s.length()){
            return true;
        }
        if(dp[i]!=-1){
            if(dp[i]==0){
                return true;
            }
            return false;
        }
        string temp="";
        bool ans=false;
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(m[temp]>0){
                ans=ans || ret(s,j+1,m,dp);
            }
        }
        if(ans==true){
            dp[i]=0;
        }
        else{
            dp[i]=1;
        }
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>m;
        for(auto it:wordDict){
            m[it]++;
        }
        vector<int>dp(s.length(),-1);
        return ret(s,0,m,dp);
    }
};