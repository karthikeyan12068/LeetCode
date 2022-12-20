class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>dp(rooms.size(),-1);
        dp[0]=1;
        list<int>l1;
        l1.push_back(0);
        while(!l1.empty()){
            for(int i=0;i<rooms[l1.front()].size();i++){
                if(dp[rooms[l1.front()][i]]==-1){
                    l1.push_back(rooms[l1.front()][i]);
                    dp[rooms[l1.front()][i]]=1;
                }
            }
            l1.pop_front();
        }
        for(auto it:dp){
            if(it==-1){
                return false;
            }
        }
        return true;
    }
};