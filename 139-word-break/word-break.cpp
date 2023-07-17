class Solution {
public:
    vector<int>dp;
    bool ret(string &s,int i,unordered_map<string,int>&m){
        if(i==s.length()){
            return true;
        }
        if(dp[i]!=-1){
            if(dp[i]==0){
                return false;
            }
            return true;
        }
        string temp="";
        bool ans=true;
        int f=0;
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(m[temp]>0){
                ans=ans && ret(s,j+1,m);
                if(ans==true){
                    f=1;
                    break;
                }
                else{
                    ans=true;
                }
            }
            
        }
        if(f==1){
            dp[i]=1;
        }
        else{
            ans=false;
            dp[i]=0;
        }
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length(),-1);
        unordered_map<string,int>m;
        for(auto it:wordDict){
            m[it]++;
        }
        return ret(s,0,m);
    }
};