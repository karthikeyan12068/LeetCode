class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                m[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        for(auto &it:m){
            reverse(it.second.begin(),it.second.end());
            for(auto it1:it.second){
                ans.push_back(it1);
            }
        }
        return ans;
    }
};