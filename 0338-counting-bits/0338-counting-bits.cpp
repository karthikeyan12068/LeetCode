class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        for(int i=0;i<=n;i++){
            if(i==0){
                v[i]=0;
            }
            else{
                int dec=i;
                int c=0;
                while(dec>0){
                    if(dec%2!=0){
                        c++;
                    }
                    dec=dec/2;
                }
                v[i]=c;
            }
        }
        return v;
    }
};