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
    void ret(TreeNode* root,unordered_map<int,int>&m,int &val){
        if(root!=NULL){
            m[root->val]++;
            val=max(val,m[root->val]);
            ret(root->left,m,val);
            ret(root->right,m,val);
        }
    }
    vector<int> findMode(TreeNode* root) {
       unordered_map<int,int>m;
       int max1=-1;
       ret(root,m,max1);
       vector<int>ans;
        for(auto it:m){
            if(it.second==max1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};