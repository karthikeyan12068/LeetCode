class Solution {
public:
    void ret(vector<int>& nums,int i,vector<int>&temp,set<vector<int>>&s){
        if(i==nums.size()){
            s.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        ret(nums,i+1,temp,s);
        temp.pop_back();
        ret(nums,i+1,temp,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        vector<int>temp;
        ret(nums,0,temp,s);
        vector<vector<int>>ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};