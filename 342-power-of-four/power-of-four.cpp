class Solution {
public:
    bool hdp(double z) {
        if (ceil((float) z / 1.0) == floor((float) z / 1.0)) {
            return false;
        }
        return true;
    }
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        double val=log(n)/log(4);
        return !hdp(val);
    }
};