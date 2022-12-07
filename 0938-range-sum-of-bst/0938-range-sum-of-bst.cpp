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
    int pre(TreeNode* root,int low,int high){
        if(root==NULL){
            return 0;
        }
        int left=(root->val>=low && root->val<=high)?root->val+pre(root->left,low,high):0+pre(root->left,low,high);
        int right=(root->val>=low && root->val<=high)?root->val+pre(root->right,low,high):0+pre(root->right,low,high);
        return left+right;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        return (pre(root,low,high))/2;
        
    }
};