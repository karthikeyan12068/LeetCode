class Solution {
public:
    
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=accumulate(nums.begin(),nums.end(),0);
        while(l<=r){
            int mid=(l+r)/2;
            int c=0,sum=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>mid){
                    c=10e7;
                    break;
                }
                if(sum+nums[i]>mid){
                    sum=nums[i];
                    c++;
                }
                else{
                    sum+=nums[i];
                }
            }
            if(sum>0){
                c++;
            }
            if(c>k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};