class Solution {
public:
    double ret(double x, long long n){
        if(n==1){
            return x;
        }
        if(n%2==0){
            return ret(x*x,n/2);
        }
        return x*ret(x*x,n/2);
        
    }
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            x=1/x;
            n=abs(n);
        }
        return ret(x,n);
    }
};