class Solution {
public:
    void ret(vector<int>& nums,int i,vector<int>temp,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        ret(nums,i+1,temp,ans);
        temp.pop_back();
        ret(nums,i+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        ret(nums,0,{},ans);
        return ans;
    }
};