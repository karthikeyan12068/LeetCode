class Solution {
public:
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<q.size();i++){
            auto it=lower_bound(nums.begin(),nums.end(),q[i]);
            int ind=it-nums.begin()+1;
            v.push_back(min(n,ind));
            if(q[i]-nums[v.back()-1]<0){
                v.back()--;
            }
            
        }
        return v;
    }
};