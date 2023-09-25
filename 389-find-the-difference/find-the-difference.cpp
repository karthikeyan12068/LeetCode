class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>v(27);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            v[t[i]-'a']++;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]%2!=0){
                return i+'a';
            }
        }
        return 'z';
    }
};