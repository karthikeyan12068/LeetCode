class Solution {
public:
    int tribonacci(int n) {
        vector<int>v1(n+1);
        if(n<=2){
            if(n==0){
                return 0;
            }
            return 1;
        }
        else{
            v1[0]=0;
            v1[1]=1;
            v1[2]=1;
            for(int i=3;i<n+1;i++){
                v1[i]=v1[i-1]+v1[i-2]+v1[i-3];
            }
        }
        return v1[n];
    }
};