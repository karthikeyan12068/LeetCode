class Solution {
public:
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,int>m;
        for(auto it:arr){
            m[it]=1;
        }
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            int c=0;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    if(m[arr[i]/arr[j]]!=0){
                        long long int mul=((long long int)m[arr[j]]%1000000007*(long long int)m[arr[i]/arr[j]]%1000000007)%1000000007;
                        c=((long long int)c%1000000007+(long long int)mul%1000000007)%1000000007;
                    }
                }
            }
            m[arr[i]]=(long long int)m[arr[i]]%1000000007+c%1000000007;
        }
        long long int ans=0;
        for(auto it:m){
            ans+=it.second%1000000007%1000000007;
        }
        return ans%1000000007%1000000007;
    }
};