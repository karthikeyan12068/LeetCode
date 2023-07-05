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
void ret(TreeNode* root,int h,vector<vector<int>>&ans){
    if(root!=NULL){
        if(h>ans.size()){
            ans.push_back({root->val});
        }
        else{
            ans[h-1].push_back(root->val);
        }
        ret(root->left,h+1,ans);
        ret(root->right,h+1,ans);
    }
}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        ret(root,1,v);
        return v;
    }
};