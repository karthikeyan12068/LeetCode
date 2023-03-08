class Solution {
public:
    bool ret(vector<int>&piles,int h,int time){
        int t=0;
        for(int i=0;i<piles.size();i++){
            int mul=ceil((double)piles[i]/time);
            t+=mul;
        }
        return t<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int left=1,right=1e9*2;
        while(left<right){
            
            int mid=(left+right)/2;
            if(ret(piles,h,mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
            cout<<mid<<" "<<left<<" "<<right<<"\n";
        }
        return left;
    }
};