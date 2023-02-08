class Solution {
public:
    
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        if(nums.size()==2){
            return 1;
        }
        for(int i=1;i<nums.size();i++){
            nums[i]=max(nums[i]+i,nums[i-1]);
        }
        int end=nums[0],ans=1;
        while(end<nums.size()-1){
            ans++;
            end=nums[end];
            //cout<<end<<"\n";
        }
        return ans;
    }
};