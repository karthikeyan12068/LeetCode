class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=accumulate(weights.begin(),weights.end(),0);
        int l=1,r=sum;
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            int s=0;
            int d=1;
            for(int i=0;i<weights.size();i++){
                if(s+weights[i]<=mid){
                    s+=weights[i];
                }
                else{
                    d++;
                    s=weights[i];
                }
                if(weights[i]>mid){
                    d=INT_MAX;
                    break;
                }
            }
            if(d>days){
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};