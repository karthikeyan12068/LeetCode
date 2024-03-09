class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(auto it:nums1){
            auto it1=lower_bound(nums2.begin(),nums2.end(),it);
            if(it1!=nums2.end() && *it1==it){
                return it;
            }
        }
        return -1;
    }
};