class Solution {
public:
    void ret(vector<int>&temp,int i,int k,vector<int>&t,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(t);
            return;
        }
        if(i==temp.size()){
            return;
        }
        t.push_back(temp[i]);
        ret(temp,i+1,k-1,t,ans);
        t.pop_back();
        ret(temp,i+1,k,t,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>v;
        vector<int>t;
        for(int i=1;i<=n;i++){
            t.push_back(i);
        }
        vector<int>s;
        ret(t,0,k,s,v);
        return v;
    }
};