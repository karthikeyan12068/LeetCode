class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int l=1,r=*max_element(bloomDay.begin(),bloomDay.end());
        long long int ans=-1;
        if((long long int)m*k>bloomDay.size()){
            return -1;
        }
        while(l<=r){
            long long int mid=(l+r)/2;
            long long int nob=0,c=0;
            for(long long int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    c++;
                    if(c==k){
                        nob++;
                        c=0;
                    }
                }
                else{
                    c=0;
                }
            }
            if(nob>=m){
                ans=mid;
                r=mid-1;
            }
            else{
                
                l=mid+1;
            }
        }
        return ans;
    }
};