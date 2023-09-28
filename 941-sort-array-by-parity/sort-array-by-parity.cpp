class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        list<int>l;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                l.push_front(nums[i]);
            }
            else{
                l.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(auto it:l){
            ans.push_back(it);
        }
        return ans;
    }
};