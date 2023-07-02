class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(auto it:s){
            m[it]++;
        }
        priority_queue<pair<int,char>>q;
        for(auto it:m){
            q.push({it.second,it.first});
        }
        string ans="";
        while(!q.empty()){
            for(int i=0;i<q.top().first;i++){
                ans+=q.top().second;
            }
            q.pop();
        }
        return ans;
    }
};