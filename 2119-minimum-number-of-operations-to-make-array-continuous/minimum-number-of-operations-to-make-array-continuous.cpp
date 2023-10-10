class Solution {
public:
 
    int minOperations(vector<int>& nums) {
        set<int>s;
        int n=nums.size();
        for(auto it:nums){
            s.insert(it);
        }
        nums.clear();
        for(auto it:s){
            nums.push_back(it);
        }
        int val=INT_MAX;
        for(int i=0;i<nums.size();i++){
            auto it=upper_bound(nums.begin()+i+1,nums.end(),nums[i]+(n-1));
            int ind=it-nums.begin();
            int dis=ind-i;
            val=min(val,n-dis);
        }
        return val;
    }
};