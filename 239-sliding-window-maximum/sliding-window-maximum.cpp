class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>m1;
        int i=0,j=k-1;
        vector<int>ans;
        for(int i=0;i<k;i++){
            m1[nums[i]]++;
        }
        
        while(j<nums.size()){
            auto it=m1.rbegin();
            ans.push_back(it->first);
            m1[nums[i]]--;
            if(m1[nums[i]]==0){
                m1.erase(nums[i]);
            }
            i++;
            j++;
            if(j<nums.size()){
                m1[nums[j]]++;
            }
        }
        return ans;
    }
};