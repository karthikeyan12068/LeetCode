class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]=i;
        }
        vector<int>ans;
        for(auto it:nums1){
            int ind1=-1;
            int ind=m[it];
            for(int j=ind+1;j<nums2.size();j++){
                if(nums2[j]>it){
                    ind1=nums2[j];
                    break;
                }
            }
            ans.push_back(ind1);
        }
        return ans;
    }
};