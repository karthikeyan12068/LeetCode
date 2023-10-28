class Solution {
public:
    long long int dp[20001][22];
    long long int ret(int i,vector<char>&vow,long long int prev,int &n){
        if(i==n){
            return 1;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        long long int ans=0;
        if(i==0){
            for(auto it:vow){
                ans+=ret(i+1,vow,it-'a',n)%1000000007%1000000007;
            }
        }
        else{
            if(char((prev+'a'))=='a'){
                ans+=ret(i+1,vow,'e'-'a',n)%1000000007%1000000007;
            }
            if(char((prev+'a'))=='e'){
                ans+=(ret(i+1,vow,'a'-'a',n)%1000000007+ret(i+1,vow,'i'-'a',n)%1000000007)%1000000007;
            }
            if(char((prev+'a'))=='i'){
                for(auto it:vow){
                    if(it!='i'){
                        ans+=ret(i+1,vow,it-'a',n)%1000000007%1000000007;
                    }
                }
            }
            if(char((prev+'a'))=='o'){
                ans+=(ret(i+1,vow,'i'-'a',n)%1000000007+ret(i+1,vow,'u'-'a',n)%1000000007)%1000000007;
            }
            if(char((prev+'a'))=='u'){
                ans+=ret(i+1,vow,'a'-'a',n)%1000000007%1000000007;
            }
        }
        return dp[i][prev+1]=ans%1000000007%1000000007;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        vector<char>vow={'a','e','i','o','u'};
        return ret(0,vow,-1,n);
    }
};