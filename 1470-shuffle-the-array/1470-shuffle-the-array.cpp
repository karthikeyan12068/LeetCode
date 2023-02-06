class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>z;
        for(int i=0;i<n;i++){
            z.push_back(nums[i]);
            z.push_back(nums[i+n]);
        }
        return z;
        
    }
};