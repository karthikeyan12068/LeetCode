class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0,maxsum=INT_MIN,sum1=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxsum=max(maxsum,sum);
            if(sum<=0){
                sum=0;
            }
            sum1+=nums[i];
        }
        if(maxsum<0){
            return maxsum;
        }
        int maxsum1=sum1,rep=0;
        for(int i=0;i<nums.size();i++){
            rep+=nums[i];
            maxsum1=max(maxsum1,sum1-rep);
            if(rep>=0){
                rep=0;
            }
        }
        return max(maxsum,maxsum1);
    }
};