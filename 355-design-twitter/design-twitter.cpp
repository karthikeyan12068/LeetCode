class Twitter {
public:
    int t=1;
    vector<list<pair<int,int>>>v;
    map<int,set<int>>follow1;
    Twitter() {
        vector<list<pair<int,int>>>v1(501);
        v=v1;
    }
    
    void postTweet(int userId, int tweetId) {
        follow(userId,userId);
        if(v[userId].size()>=10){
            v[userId].pop_front();
        }
        v[userId].push_back({t,tweetId});
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>q;
        for(auto it:follow1[userId]){
            for(auto it1:v[it]){
                q.push({it1.first,it1.second});
            }
        }
        vector<int>ans;
        while(!q.empty() && ans.size()<10){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follow1[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it=follow1[followerId].find(followeeId);
        if(it!=follow1[followerId].end()){
            follow1[followerId].erase(it);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */