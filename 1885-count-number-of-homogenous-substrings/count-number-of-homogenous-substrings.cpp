class Solution {
public:
    int countHomogenous(string s) {
        int ans=0;
        int i=0;
        while(i<s.length()){
            int j=i;
            long long int c=0;
            while(j<s.length() && s[i]==s[j]){
                c++;
                j++;
            }
            c=c*(c+1);
            c/=2;
            c%=1000000007;
            c%=1000000007;
            ans+=c;
            ans%=1000000007;
            ans%=1000000007;
            i=j;
        }
        return ans%1000000007;
    }
};