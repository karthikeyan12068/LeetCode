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
        if(high%2==0){
            high--;
        }
        if(low==high){
            c=1;
        }
        else{
            if(low>high){
                return 0;
            }
            else{
                c=2;
            }
        }
        return c+(high-low-1)/2;
    }
};