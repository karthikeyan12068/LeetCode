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
int build(TreeNode* root){
    if(root==NULL){
        return -1;
    }
    int left=1+build(root->left);
    int right=1+build(root->right);
    if(left==right){
        return left;
    }
    else{
        if(abs(right-left)<=1){
            return max(right,left);
        }
        else{
            return 100000;
        }
    }
    
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(build(root)<=10000){
            return true;
        }
        return false;
    }
};