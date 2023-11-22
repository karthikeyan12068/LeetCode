class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        vector<pair<int,int>>v;
        map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        for(auto it:m){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=v.size()-2;i>=0;i--){
            v[i].second+=v[i+1].second;
            ans+=v[i+1].second;
        }
        return ans;
    }
};