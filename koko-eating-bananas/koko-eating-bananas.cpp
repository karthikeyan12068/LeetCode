class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        long long int l=1,r=piles.back()+1;
        long long int ans=-1;
        while(l<=r){
            long long int mid=(l+r)/2;
            long long int h1=0;
            for(long long int i=0;i<piles.size();i++){
                h1+=ceil((double)piles[i]/mid);
            }
            if(h1>h){
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