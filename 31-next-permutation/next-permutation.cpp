class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-1;i>=0;i--){
            int val=INT_MAX,ind=-1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    if(val>nums[j]){
                        val=nums[j];
                        ind=j;
                    }
                }
            }
            if(ind!=-1){
                swap(nums[i],nums[ind]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
        return;
    }
};