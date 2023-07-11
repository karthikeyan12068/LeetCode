class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto it:nums){
            q.push(it);
        }
        int ans;
        while(k--){
            ans=q.top();
            q.pop();
        }
        return ans;
    }
};