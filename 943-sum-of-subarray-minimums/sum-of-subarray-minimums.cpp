class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>s;
        vector<int>lmin(arr.size(),-1),rmin(arr.size(),arr.size());
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && arr[i]<=arr[s.top()]){
                rmin[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=arr.size()-1;i>=0;i--){
            while(!s.empty() && arr[i]<arr[s.top()]){
                lmin[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        long long int res=0;
        for(int i=0;i<arr.size();i++){
            long long int temp=(i-lmin[i])*(rmin[i]-i)%1000000007;
            temp=((temp*arr[i])%1000000007)%1000000007;
            res=(res+temp)%1000000007;
        }
        return res;
    }
};