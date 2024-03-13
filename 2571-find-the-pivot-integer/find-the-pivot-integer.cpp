class Solution {
public:
    int pivotInteger(int n) {
        vector<int>left(n),right(n);
        for(int i=1;i<=n;i++){
            if(i==1){
                left[i-1]=1;
                right[n-i]=n;
            }
            else{
                left[i-1]=i+left[i-2];
                right[n-i]=(n-(i-1))+right[n-i+1];
            }
        }
        for(int i=0;i<n;i++){
            if(left[i]==right[i]){
                return i+1;
            }
        }
        return -1;
    }
};