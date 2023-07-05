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
int ret(TreeNode* root,int &ans){
    int left=0,right=0;
    if(root->left!=NULL){
        left=ret(root->left,ans);
    }
    if(root->right!=NULL){
        right=ret(root->right,ans);
    }
    ans=max(ans,left+right+1);
    return 1+max(left,right);
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        ret(root,ans);
        return ans-1;
    }
};