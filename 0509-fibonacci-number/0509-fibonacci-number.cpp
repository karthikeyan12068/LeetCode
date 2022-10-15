class Solution {
public:
    int fib1(int n,map<int,int>&m1){
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(m1[n]!=0){
            return m1[n];
        }
        return m1[n]=fib1(n-1,m1)+fib1(n-2,m1);
    }
    int fib(int n) {
        map<int,int>m1;
        return fib1(n,m1);
    }
};