class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0;
        for(int i=0;i<t.length();i++){
            if(s[l]==t[i]){
                l++;
                if(l==s.length()){
                    return true;
                }
            }
        }
        if(s.empty()){
            return true;
        }
        return false;
    }
};