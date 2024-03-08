class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>m;
        int f=0;
        for(auto it:nums){
            m[it]++;
            f=max(f,m[it]);
        }
        int c=0;
        for(auto it:m){
            if(it.second==f){
                c+=f;
            }
        }
        return c;

    }
};