class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int>q;
        for(auto it:nums){
            q.push(it);
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};