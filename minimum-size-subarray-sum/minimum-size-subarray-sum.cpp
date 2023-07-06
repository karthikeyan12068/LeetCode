class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,sum=0;
        int len=INT_MAX;
        while(true){
            while(r<nums.size() && sum<target){
                sum+=nums[r];
                r++;
            }
            if(sum>=target){
                len=min(len,r-l);
            }
            while(l<=r && sum>=target){
                sum-=nums[l];
                len=min(len,(r-l));
                l++;
                
            }
            if(r>=nums.size()){
                break;
            }
        }
        if(len==INT_MAX){
            return 0;
        }
        return len;
    }
};