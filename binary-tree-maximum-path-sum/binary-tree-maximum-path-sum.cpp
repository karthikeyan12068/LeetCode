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
    if(root==NULL){
        return 0;
    }
    int left=ret(root->left,ans);
    int right=ret(root->right,ans);
    int val=max(root->val,max(root->val+left,root->val+right));
    ans=max(ans,max(val,root->val+left+right));
    if(val<0){
        return 0;
    }
    return val;
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        ret(root,ans);
        return ans;
    }
};