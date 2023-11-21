class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        map<long long int,long long int>m;
        
        for(int i=0;i<nums.size();i++){
            string temp=to_string(nums[i]);
            reverse(temp.begin(),temp.end());
            long long int t=stoll(temp);
            m[nums[i]-t]++;
        }
        long long int ans=0;
        for(auto it:m){
            long long int x=it.second*(it.second-1);
            x/=2;
            ans+=x;
            ans%=1000000007;
            ans%=1000000007;
        }
        return ans%1000000007;
    }
};