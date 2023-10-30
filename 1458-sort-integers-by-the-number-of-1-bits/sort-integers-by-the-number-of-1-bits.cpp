class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,multiset<int>>m;
        for(int i=0;i<arr.size();i++){
            m[__builtin_popcount(arr[i])].insert(arr[i]);
        }
        vector<int>ans;
        for(auto it:m){
            for(auto it1:it.second){
                ans.push_back(it1);
            }
        }
        return ans;
    }
};