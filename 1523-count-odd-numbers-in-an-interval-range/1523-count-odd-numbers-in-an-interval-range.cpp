class Solution {
public:
    int countOdds(int low, int high) {
        int c=0;
        if(low>high){
            swap(low,high);
        }
        if(low%2==0){
            low++;
        }
        while(low<=high){
            low+=2;
            c++;
        }
        return c;
    }
};