class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char,int>m1;
        m1['a']++;
        m1['e']++;
        m1['i']++;
        m1['o']++;
        m1['u']++;
        int left=0,right=0;
        for(int i=0;i<s.length();i++){
            if(m1[tolower(s[i])]!=0 || m1[toupper(s[i])]!=0){
                if(i>=s.length()/2){
                    right++;
                }
                else{
                    left++;
                }
            }
        }
        if(left==right){
            return true;
        }
        return false;
    }
};