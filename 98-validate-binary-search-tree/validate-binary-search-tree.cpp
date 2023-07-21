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
bool ret(TreeNode* root,long long int l,long long int r){
    if(root==NULL){
        return true;
    }
    if(root->val>l && root->val<r){
        return ret(root->left,l,root->val) && ret(root->right,root->val,r);
    }
    return false;
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return ret(root->left,LONG_MIN,root->val) && ret(root->right,root->val,LONG_MAX);
    }
};