class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int maxpower=0,curpower=0;
        int i=0,j=tokens.size()-1;
        while(i<=j){
            int f=0;
            while(i<=j && power>=tokens[i]){
                curpower++;
                maxpower=max(maxpower,curpower);
                power-=tokens[i];
                i++;
                f=1;
            }
            while(j>=i && curpower>0 && power<tokens[i]){
                curpower--;
                power+=tokens[j];
                j--;
                f=1;
            }
            if(f==0){
                break;
            }
        }
        return maxpower;
    }
};