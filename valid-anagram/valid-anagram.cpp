class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m;
        for(auto &it:s){
            m[it]++;
        }
        for(auto &it:t){
            if(m[it]==0){
                return false;
            }
            m[it]--;
            if(m[it]==0){
                m.erase(it);
            }
        }
        if(!m.empty()){
            return false;
        }
        return true;
    }
};