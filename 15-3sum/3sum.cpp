class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int l=i+1,r=nums.size()-1;
            int sum=-nums[i];
            while(l<r){
                int temp=nums[l]+nums[r];
                if(temp<sum){
                    l++;
                }
                else{
                    if(temp==sum){
                        v.insert({nums[i],nums[l],nums[r]});
                    }
                    r--;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto it:v){
            ans.push_back(it);
        }
        return ans;
    }
};