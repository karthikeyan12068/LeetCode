class Solution {
public:
    int smallestDivisor(vector<int>& nums, int thr) {
        sort(nums.begin(),nums.end());
        int l=1,r=nums.back(),ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                sum+=ceil((float)nums[i]/mid);
            }
            if(sum>thr){
                l=mid+1;
            }
            else{
                
                r=mid-1;
            }
        }
        return l;
    }
};