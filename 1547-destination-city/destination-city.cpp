class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int>m;
        for(auto it:paths){
            m[it[0]]=-1;
            if(m[it[1]]==0){
                m[it[1]]++;
            }
        }
        for(auto it:m){
            if(it.second>0){
                return it.first;
            }
        }
        return "";
    }
};