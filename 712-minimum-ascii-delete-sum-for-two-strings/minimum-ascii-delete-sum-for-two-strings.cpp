class Solution {
public:
    int ret(string &s1, string &s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.length() || j==s2.length()){
            int ans=0;
            int i1=i,j1=j;
            while(i1<s1.length()){
                ans+=(int)s1[i1];
                i1++;
            }
            while(j1<s2.length()){
                ans+=(int)s2[j1];
                j1++;
            }
            return ans;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        if(s1[i]==s2[j]){
            ans=0+ret(s1,s2,i+1,j+1,dp);
        }
        else{
            ans=min((int)s1[i]+ret(s1,s2,i+1,j,dp),(int)s2[j]+ret(s1,s2,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.length(),vector<int>(s2.length(),-1));
        return ret(s1,s2,0,0,dp);
    }
};