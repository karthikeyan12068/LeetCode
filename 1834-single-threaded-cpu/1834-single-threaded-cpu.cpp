#include <algorithm> // for sort()
#include <iostream>
#include <vector> // for 2D vector
class Solution {
public:
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>v;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<> > pq;
        int i=0;
        map<pair<int,int>,list<int>>m1;
        for(int i=0;i<tasks.size();i++){
            m1[{tasks[i][0],tasks[i][1]}].push_back(i);
        }
        //cout<<tasks.size()<<" "<<m1.size();
        int n=tasks.size();
        sort(tasks.begin(), tasks.end());
        int time=tasks[0][0];
        /*for(auto it:tasks){
            cout<<it[0]<<" "<<it[1]<<"\n";
        }*/
        while(i<n){
           
            while(i<n && tasks[i][0]<=time){
                if(i>=n){
                    break;
                }
                pq.push({tasks[i][1],m1[{tasks[i][0],tasks[i][1]}].front()});
                m1[{tasks[i][0],tasks[i][1]}].pop_front();
                i++;
            }
            
            if(!pq.empty()){
                time+=pq.top().first;
                v.push_back(pq.top().second);
                pq.pop();
            }
            else{
                if(i<n){
                    time=tasks[i][0];
                }
            }
        }
        if(!pq.empty()){
            while (!pq.empty()) {
                v.push_back(pq.top().second);
                pq.pop();
            }
        }
        return v;
    }
};