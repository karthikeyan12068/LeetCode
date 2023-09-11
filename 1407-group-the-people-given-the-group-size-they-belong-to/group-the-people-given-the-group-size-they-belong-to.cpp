class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>>v;
        for(int i=0;i<groupSizes.size();i++){
            v.push_back({groupSizes[i],i});
        }
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        for(int i=0;i<groupSizes.size();i++){
            vector<int>temp;
            int j;
            for(j=i;j<i+v[i].first;j++){
                temp.push_back(v[j].second);
            }
            i=j-1;
            ans.push_back(temp);
        }
        return ans;
    }
};