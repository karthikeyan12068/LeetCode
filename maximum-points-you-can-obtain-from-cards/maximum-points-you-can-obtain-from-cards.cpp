class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int sum1=0,win=card.size()-k;
        for(int i=win;i<card.size();i++){
            sum1+=card[i];
        }
        
        int i=0,j=win-1;
        int ans=sum1;
        while(j<card.size()){
            ans=max(ans,sum1);
            sum1+=card[i];
            i++;
            j++;
            if(j<card.size()){
                sum1-=card[j];
            }
        }
        return ans;
    }
};