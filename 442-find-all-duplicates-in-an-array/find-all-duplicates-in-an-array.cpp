class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]*=10;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int actind=nums[i]/10;
            actind--;
            if(nums[actind]%10==1){
                ans.push_back(nums[i]/10);
                nums[actind]++;
            }else{
                if(nums[actind]%10==0){
                    nums[actind]++;
                }else{
                    continue;
                }
            }
        }
        return ans;
    }
};