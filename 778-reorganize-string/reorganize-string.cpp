class Solution {
public:
    string reorganizeString(string s) {
        map<int,int>m;
        for(auto it:s){
            m[it]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto it:m){
            q.push({it.second,it.first});
        }
        string temp="";
        while(!q.empty()){
            pair<int,int>p=q.top();
            q.pop();
            if(temp.empty()){
                temp+=p.second;
                p.first--;
                if(p.first!=0){
                    q.push(p);
                }
            }
            else{
                if(temp.back()==p.second){
                    if(q.empty()){
                        return "";
                    }
                    else{
                        pair<int,int>p1=q.top();
                        q.pop();
                        if(p.first!=0){
                            q.push(p);
                        }
                        temp+=p1.second;
                        p1.first--;
                        if(p1.first!=0){
                            q.push(p1);
                        }
                    }
                }
                else{
                    temp+=p.second;
                    p.first--;
                    if(p.first!=0){
                       q.push(p);
                    } 
                }
            }
        }
        return temp;
    }
};