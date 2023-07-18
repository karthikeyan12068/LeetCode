class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int,int>m1;
        for(auto it:hand){
            m1[it]++;
        }
        int ans=hand.size()/groupSize;
        while(ans--){
            int x=m1.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(m1[x]>0){
                    m1[x]--;
                    if(m1[x]==0){
                        m1.erase(x);
                    }
                }
                else{
                    return false;
                }
                x++;
            }
        }
        return true;
    }
};