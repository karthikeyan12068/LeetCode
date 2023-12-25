class Solution {
public:
    int dp[101];
    int ret(int i,string &s,unordered_map<string,int>&m){
        if(i>=s.length()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        string temp="";
        for(int j=i;j<min((int)s.length(),i+2);j++){
            temp+=s[j];
            if(m[temp]>0){
                ans+=ret(j+1,s,m);
            }
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        unordered_map<string,int>m;
        m["1"]++;
        m["2"]++;
        m["3"]++;
        m["4"]++;
        m["5"]++;
        m["6"]++;
        m["7"]++;
        m["8"]++;
        m["9"]++;
        m["10"]++;
        m["11"]++;
        m["12"]++;
        m["13"]++;
        m["14"]++;
        m["15"]++;
        m["16"]++;
        m["17"]++;
        m["18"]++;
        m["19"]++;
        m["20"]++;
        m["21"]++;
        m["22"]++;
        m["23"]++;
        m["24"]++;
        m["25"]++;
        m["26"]++;
        return ret(0,s,m);
    }
};