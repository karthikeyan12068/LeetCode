class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size()-1;i++){
            int diff=nums[i+1]-nums[i];
            for(int j=i+2;j<nums.size();j++){
                if(nums[j]-nums[j-1]==diff){
                    sum++;
                }
                else{
                    break;
                }
            }
        }
        return sum;
    }
};