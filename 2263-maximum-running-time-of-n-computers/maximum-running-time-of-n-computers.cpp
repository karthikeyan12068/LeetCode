class Solution {
public:
    
    bool isPossible(vector<int> &batteries,long long target,long long n){
        long long extra=0;
        for(int i=0;i<batteries.size();i++){
            if(batteries[i]>=target)extra+=target;
            else extra+=batteries[i];
        }
        return extra>=n*target;
    }

    long long maxRunTime(int n, vector<int>& batteries){
        long long start=1;
        long long end=0;
        for(int i=0;i<batteries.size();i++)end+=batteries[i];
        end/=n;
        while(start<=end){
            long long mid=(start+end)/2;
            if(isPossible(batteries,mid,n))start=mid+1;
            else end=mid-1;
        }
        return start-1;
    }
};