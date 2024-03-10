class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        for(auto it:nums1){
            m[it]++;
        }
        set<int>s;
        for(auto it:nums2){
            if(m.find(it)!=m.end()){
                s.insert(it);
            }
        }
        vector<int>ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};