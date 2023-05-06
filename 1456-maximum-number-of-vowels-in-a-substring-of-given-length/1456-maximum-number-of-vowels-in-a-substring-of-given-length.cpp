class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int>dp(s.length(),0);
        
        if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u'){
            dp[0]=1;
        }
        for(int i=1;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
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
            if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u'){
                sum++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};