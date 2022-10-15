class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        for(int i=0;i<=n;i++){
            if(i==0){
                v[i]=0;
            }
            else{
                if(i%2!=0){
                    v[i]=v[i/2]+1;
                }
                else{
                    v[i]=v[i/2];
                }
            }
        }
        return v;
    }
};