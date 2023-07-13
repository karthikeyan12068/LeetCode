class Solution {
public:
    #define MOD 1000000007
    long long int ret(long long int x,long long int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(n%2==0){
            return (ret((x*x)%MOD,n/2)%MOD)%MOD;
        }
        return (x*(ret((x*x)%MOD,n/2)%MOD)%MOD)%MOD;
    }
    int countGoodNumbers(long long n) {
        long long int e=0,o=0;
        if(n%2==0){
           e=n/2;
           o=n/2;
        } 
        else{
            e=n/2+1;
            o=n/2;
        }
        return ((ret(5,e)%MOD)*(ret(4,o)%MOD))%MOD;
    }
};