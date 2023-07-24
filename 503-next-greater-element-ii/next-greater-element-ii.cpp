class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int j=(i+1)%nums.size();
            int f=0;
            while(j!=i){
                if(nums[j]>nums[i]){
                    ans.push_back(nums[j]);
                    f=1;
                    break;
                }
                else{
                    j++;
                    j%=nums.size();
                }
            }
            if(f==0){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};