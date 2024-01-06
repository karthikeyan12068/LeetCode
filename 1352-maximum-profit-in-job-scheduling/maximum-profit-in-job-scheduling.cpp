class Solution {
public:
    int dp[50001];
    int ret(vector<pair<pair<int,int>,int>>&v,int i){
        if(i==v.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=v[i].second,ntake=0;
        std::pair<std::pair<int, int>, int> value_to_find = { {v[i].first.second, 0}, 0 }; 
        auto it = std::lower_bound(
        v.begin(),
        v.end(),
        value_to_find,
        [](const pair<pair<int, int>, int>& a, const std::pair<std::pair<int, int>, int>& b) {
            return a.first < b.first; 
        }
    );
        if(it!=v.end()){
            int ind=it-v.begin();
            take+=ret(v,ind);
        }
        ntake+=ret(v,i+1);
        return dp[i]=max(take,ntake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        vector<pair<pair<int,int>,int>>v;
        for(int i=0;i<startTime.size();i++){
            v.push_back({{startTime[i],endTime[i]},profit[i]});
        }
        sort(v.begin(), v.end());        
        return ret(v,0);
    }
};