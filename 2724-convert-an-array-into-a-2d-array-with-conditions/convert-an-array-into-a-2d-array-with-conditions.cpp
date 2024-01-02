class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        vector<vector<int>>ans;
        while(!m.empty()){
            vector<int>v;
            for(auto &it:m){
                v.push_back(it.first);
                it.second--;
            }
            for(auto it:v){
                if(m[it]==0){
                    m.erase(m.find(it));
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};