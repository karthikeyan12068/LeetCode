class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<long long>s;
        vector<long long>rmin(nums.size(),nums.size());
        vector<long long>lmin(nums.size(),-1);
        long long n=nums.size();
        for(long long i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>nums[i]){
                rmin[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(long long i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>=nums[i]){
                lmin[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        vector<long long>v1(n);
        for(long long i=0;i<n;i++){
            v1[i]=(rmin[i]-i)*(i-lmin[i]);
        }
        
        while(!s.empty()){
            s.pop();
        }
        rmin.clear();
        lmin.clear();
        rmin.resize(nums.size(),nums.size());
        lmin.resize(nums.size(),-1);
        //vector<long long>v(n);
        for(long long i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<nums[i]){
                rmin[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(long long i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i]){
                lmin[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        vector<long long>v2(n);
        for(long long i=0;i<n;i++){
            v2[i]=(rmin[i]-i)*(i-lmin[i]);
        }
        long long x=0;
        for(long long i=0;i<n;i++){
            x+=(v2[i]*nums[i])-(v1[i]*nums[i]);
        }
        return x;
    }
};