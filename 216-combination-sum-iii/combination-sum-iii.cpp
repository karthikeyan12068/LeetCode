class Solution {
public:
    vector<int>v={1,2,3,4,5,6,7,8,9};
    void ret(vector<vector<int>>&ans,int i,int k,int n,vector<int>&temp){
        if(k==0){
            if(n==0){
                ans.push_back(temp);
            }
            return;
        }
        if(i==9){
            return;
        }
        temp.push_back(v[i]);
        ret(ans,i+1,k-1,n-v[i],temp);
        temp.pop_back();
        ret(ans,i+1,k,n,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>t;
        ret(ans,0,k,n,t);
        return ans;
    }
};