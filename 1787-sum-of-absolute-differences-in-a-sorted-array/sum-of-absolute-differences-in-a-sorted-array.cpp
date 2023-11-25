class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>pref(nums.size());
        vector<int>suf(nums.size());
        for(int i=1;i<nums.size();i++){
            pref[i]=pref[i-1]+nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            suf[i]=suf[i+1]+nums[i+1];
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(abs(i*nums[i]-pref[i])+(suf[i]-(nums.size()-(i+1))*nums[i]));
        }
        return ans;
    }
};