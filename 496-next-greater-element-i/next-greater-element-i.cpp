class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int>m;
        for(int i=0;i<nums2.size();i++){
            if(s.empty()){
                s.push(nums2[i]);
            }
            else{
                while(!s.empty() && s.top()<nums2[i]){
                    m[s.top()]=nums2[i];
                    s.pop();
                }
                s.push(nums2[i]);
            }
        }
        vector<int>ans;
        for(auto it:nums1){
            if(m[it]==0){
                ans.push_back(-1);
            }
            else{
                ans.push_back(m[it]);
            }
        }
        return ans;
    }
};