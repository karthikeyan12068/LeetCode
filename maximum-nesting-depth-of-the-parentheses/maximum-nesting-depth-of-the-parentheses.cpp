class Solution {
public:
    int maxDepth(string s) {
        int unclosed=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                unclosed++;
            }
            if(s[i]==')'){
                unclosed--;
            }
            ans=max(ans,unclosed);
        }
        return ans;
    }
};