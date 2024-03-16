class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int ,int> mp;
        int prefixSum = 0, maxi = 0;
        for(int i = 0 ; i < n ; i++){
            prefixSum += nums[i] > 0 ? 1 : -1;
            if(prefixSum == 0)
                maxi = i + 1;
            else{
                if(mp.contains(prefixSum))
                    maxi = max(maxi, i - mp[prefixSum]);
            }
            if(!mp.contains(prefixSum))
                mp[prefixSum] = i;
        }
        return maxi;
    }
};