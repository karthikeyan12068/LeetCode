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
int ans=0;
int ret(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int l=ret(root->left);
    int r=ret(root->right);
    ans+=abs(l-r);
    return root->val+l+r;
}
class Solution {
public:
    int findTilt(TreeNode* root) {
        if(ans!=0){
            ans=0;
        }
        ret(root);
        return ans;
    }
};