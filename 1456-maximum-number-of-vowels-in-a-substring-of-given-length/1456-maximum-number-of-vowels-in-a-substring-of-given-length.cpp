class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int>dp(s.length(),0);
        map<char,int>m1;
        m1['a']++;
        m1['e']++;
        m1['i']++;
        m1['o']++;
        m1['u']++;
        if(m1[s[0]]==1){
            dp[0]=1;
        }
        for(int i=1;i<s.length();i++){
            if(m1[s[i]]==1){
                dp[i]=dp[i-1]+1;
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        int ans=INT_MIN;
        k--;
        for(int i=k;i<s.length();i++){
            int sum=dp[i]-dp[(i-k)];
            if(m1[s[(i-k)]]==1){
                sum++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};