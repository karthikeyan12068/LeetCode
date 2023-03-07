class Solution {
public:
    bool ret(vector<int>&time,long long t,long long tar){
        long long c=0;
        for(auto it:time){
            c+=t/it;
        }
        return c>=tar;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long right=1LL*time.back()*totalTrips;
        long long left=1;
        while(left<right){
            long long mid=(left+right)/2;
            if(ret(time,mid,totalTrips)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};