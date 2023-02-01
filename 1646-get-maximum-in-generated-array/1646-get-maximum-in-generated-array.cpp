class Solution {
public:
    int getMaximumGenerated(int n) {
        int max1=0;
        vector<int>v(n+1);
        for(int i=0;i<n+1;i++){
            if(i==0){
                v[0]=0;
                max1=0;
            }
            else{
                if(i==1){
                    v[1]=1;
                    max1=1;
                }
                else{
                    if((i-2)%2==0){
                        v[i]=v[i/2];
                        max1=max(max1,v[i]);
                    }
                    else{
                        v[i]=v[i/2]+v[i/2+1];
                        max1=max(max1,v[i]);
                    }
                }
            }
        }
        return max1;
    }
};