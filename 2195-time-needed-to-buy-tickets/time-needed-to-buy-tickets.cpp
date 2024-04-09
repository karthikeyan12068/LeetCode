class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        list<pair<int,int>>l1;
        for(int i=0;i<tickets.size();i++){
            l1.push_back({tickets[i],i});
        }
        int t=0;
        while(true){
            t++;
            l1.front().first--;
            if(l1.front().first==0){
                if(l1.front().second==k){
                    return t;
                }else{
                    l1.pop_front();
                }
            }else{
                l1.push_back(l1.front());
                l1.pop_front();
            }
        }
        return t;
    }
};