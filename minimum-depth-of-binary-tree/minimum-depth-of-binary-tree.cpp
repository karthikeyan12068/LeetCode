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
void ret(TreeNode* root,int h,int &ans){
    if(root->left==NULL && root->right==NULL){
        ans=min(ans,h);
        return;
    }
    else{
        if(root->left!=NULL){
            ret(root->left,h+1,ans);
        }
        if(root->right!=NULL){
            ret(root->right,h+1,ans);
        }
    }
}
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=INT_MAX;
        ret(root,1,ans);
        return ans;
    }
};