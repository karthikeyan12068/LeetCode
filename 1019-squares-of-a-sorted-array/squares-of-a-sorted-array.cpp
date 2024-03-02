class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int>m;
        for(auto it:nums){
            m.insert(pow(it,2));
        }
        vector<int>v;
        for(auto it:m){
            v.push_back(it);
        }
        return v;
    }
};