class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        int ans=0;
        for(auto it:m){
            int c=it.second;
            while(c-2>=0 && c%3!=0){
                c-=2;
                ans++;
            }
            if(c%3==0){
                ans+=c/3;
            }
            else{
                return -1;
            }
        }
        return ans;
    }
};