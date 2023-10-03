class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto it:nums){
            ans+=(m[it]-1);
            m[it]--;
        }
        return ans;
    }
};