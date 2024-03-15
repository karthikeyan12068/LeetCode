class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zc=count(nums.begin(),nums.end(),0);
        vector<int>ans;
        if(zc>=2){
            for(int i=0;i<nums.size();i++){
                ans.push_back(0);
            }
        }
        else{
            if(zc==1){
                int prod=1;
                for(auto it:nums){
                    if(it!=0){
                        prod*=it;
                    }
                }
                for(int i=0;i<nums.size();i++){
                    if(nums[i]==0){
                        ans.push_back(prod);
                    }
                    else{
                        ans.push_back(0);
                    }
                }
            }
            else{
                int prod=1;
                for(auto it:nums){
                    prod*=it;
                }
                for(auto it:nums){
                    ans.push_back(prod/it);
                }
            }
        }
        return ans;
    }
};