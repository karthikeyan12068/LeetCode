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
TreeNode* build(TreeNode* root){
    if(root==NULL){
        return root;
    }
    root->left=build(root->left);
    root->right=build(root->right);
    swap(root->left,root->right);
    return root;
}
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        root=build(root);
        return root;
    }
};