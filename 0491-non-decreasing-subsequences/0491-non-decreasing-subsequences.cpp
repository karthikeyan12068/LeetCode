class Solution {
public:
    void ret(vector<vector<int>>&v,vector<int>t,int i,vector<int>nums,map<vector<int>,int>&m){
        if(t.size()>=2){
            if(t[t.size()-1]<t[t.size()-2]){
                return;
            }
        }
        if(i==nums.size()){
            if(m[t]==0 && t.size()>=2){
                v.push_back(t);
                m[t]++;
            }
            return;
        }
        ret(v,t,i+1,nums,m);
        t.push_back(nums[i]);
        ret(v,t,i+1,nums,m);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>t;
        map<vector<int>,int>m;
        ret(v,t,0,nums,m);
        return v;
    }
};