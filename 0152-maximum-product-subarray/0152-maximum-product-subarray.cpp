class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sum1=1,sum2=0,maxsum=-11;
        
        for(int i=0;i<nums.size();i++){
            maxsum=max(maxsum,nums[i]);
            if(nums[i]!=0){
                sum1*=nums[i];
                if(sum1>=0){
                    maxsum=max(maxsum,sum1);
                    sum2=0;
                }
                else{
                    if(sum2!=0){
                        maxsum=max(maxsum,sum1/sum2);
                    }
                    sum2=sum1;
                }
            }
            else{
                sum1=1,sum2=0;
            }
        }
        reverse(nums.begin(),nums.end());
        int ans1=maxsum;
        sum1=1,sum2=0,maxsum=-11;
        for(int i=0;i<nums.size();i++){
            maxsum=max(maxsum,nums[i]);
            if(nums[i]!=0){
                sum1*=nums[i];
                if(sum1>=0){
                    maxsum=max(maxsum,sum1);
                    sum2=0;
                }
                else{
                    if(sum2!=0){
                        maxsum=max(maxsum,sum1/sum2);
                    }
                    sum2=sum1;
                }
            }
            else{
                sum1=1,sum2=0;
            }
        }
        return max(maxsum,ans1);
    }
};