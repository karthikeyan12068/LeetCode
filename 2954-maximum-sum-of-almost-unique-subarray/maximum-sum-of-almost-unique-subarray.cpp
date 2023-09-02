
class Solution {
public:
    
    long long maxSum(vector<int>& nums, int m, int k) {
        
        if(k==1){
            return *max_element(nums.begin(),nums.end());
        }
        vector<long long int>pref(nums.size()+1);
        pref[0]=0;
        for(long long int i=1;i<=nums.size();i++){
            pref[i]=pref[i-1]+nums[i-1];
        }
        long long int i=0,j=i+k;
        j--;
        long long int x=0;
        map<long long int,long long int>m1;
        m1[nums[i]]++;
        for(long long int i1=i+1;i1<=j;i1++){
            if(nums[i1]!=nums[i1-1]){
                x++;
            }
            m1[nums[i1]]++;
        }
        
        long long int ans=-1;
        
        while(j<nums.size()){
            if(m1.size()>=m){
                ans=max(ans,pref[j+1]-pref[i]);
            }
            
            if(j+1<nums.size()){
                m1[nums[j+1]]++;
                m1[nums[i]]--;
                if(m1[nums[i]]==0){
                    m1.erase(nums[i]);
                }
            }
            i++;
            j++;
        }
        return max(0ll,ans);
    }
};