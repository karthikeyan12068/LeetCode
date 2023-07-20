class Solution {
public:
    int ret(vector<int>& nums, int k){
        map<int,int>m1;
        int sum=0;
        int l=0,r=0;
        while(r<nums.size()){
            m1[nums[r]]++;
            if(m1.size()<=k){
                sum+=(r-l)+1;
            }
            else{
                while(m1.size()>k){
                    m1[nums[l]]--;
                    if(m1[nums[l]]==0){
                        m1.erase(nums[l]);
                    }
                    l++;
                }
                sum+=(r-l)+1;
            }
            r++;
        }
        cout<<sum<<' '<<l<<'\n';
        return sum;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //cout<<ret(nums,k);
        return ret(nums,k)-ret(nums,k-1);
    }
};