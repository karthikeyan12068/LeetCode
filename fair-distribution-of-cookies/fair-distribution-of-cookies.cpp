class Solution {
public:
    void ret(vector<int>& cookies, int i,int k,vector<int>&nums,int &ans){
        if(i==cookies.size()){
            int a=INT_MIN;
            for(int j=0;j<k;j++){
                a=max(a,nums[j]);
            }
            ans=min(ans,a);
            return;
        }
        for(int j=0;j<k;j++){
            nums[j]+=cookies[i];
            ret(cookies,i+1,k,nums,ans);
            nums[j]-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>nums(k,0);
        int ans=INT_MAX;
        ret(cookies,0,k,nums,ans);
        return ans;
    }
};