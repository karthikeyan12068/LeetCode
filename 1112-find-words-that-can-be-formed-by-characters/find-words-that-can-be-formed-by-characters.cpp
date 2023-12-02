class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>v(26);
        for(auto it:chars){
            v[it-'a']++;
        }
        int ans=0;
        for(auto it:words){
            vector<int>v1(26);
            for(auto it1:it){
                v1[it1-'a']++;
            }
            int f=0;
            for(int i=0;i<26;i++){
                if(v1[i]>v[i]){
                    f=1;
                    break;
                }
            }
            if(f==0){
                ans+=it.length();
            }
        }
        return ans;
    }
};