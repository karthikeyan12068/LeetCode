/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
    
public:
    void fun(vector<TreeNode*>&ans,unordered_map<int,vector<TreeNode*>>&m1,int n){
        if(!m1[n].empty()){
            ans=m1[n];
            return;
        }
        if(n==1){
            ans.push_back(new TreeNode());
            m1[n]=ans;
            return;
        }
        for(int i=0;i<n;i++){
            int l=i,r=n-i-1;
            vector<TreeNode*>left;
            vector<TreeNode*>right;
            fun(left,m1,l);
            fun(right,m1,r);
            for(int i=0;i<left.size();i++){
                for(int j=0;j<right.size();j++){
                    ans.push_back(new TreeNode(0,left[i],right[j]));
                }
            }
        }
        m1[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>>m1;
        vector<TreeNode*>ans;
        fun(ans,m1,n);
        return ans;
    }
};