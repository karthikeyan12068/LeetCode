class Solution {
public:
    int minBitFlips(int start, int goal) {
        int s=0;
        int b1=log2(start+1);
        int b2=log2(goal+1);
        for(int i=0;i<=max(b1,b2);i++){
            if(((start>>i)&1)!=((goal>>i)&1)){
                s++;
            }
        }
        return s;
    }
};