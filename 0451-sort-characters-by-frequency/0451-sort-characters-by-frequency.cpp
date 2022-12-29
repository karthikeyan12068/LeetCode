class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m1;
        for(auto it:s){
            m1[it]++;
        }
        priority_queue<pair<int,char>>q;
        for(auto it:m1){
            q.push({it.second,it.first});
        }
        string z="";
        while(!q.empty()){
            for(int i=0;i<q.top().first;i++){
                z+=q.top().second;
            }
            q.pop();
        }
        return z;
    }
};