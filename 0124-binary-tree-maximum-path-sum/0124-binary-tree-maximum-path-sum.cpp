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
int ret(TreeNode* root,int &max1){
    if(root==NULL){
        return 0;
    }
    int cur=root->val;
    int left=ret(root->left,max1);
    int right=ret(root->right,max1);
    max1=max(cur,max(max1,max(max(cur+left,cur+right),cur+left+right)));
    return max(cur,max(cur+left,cur+right));
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max1=-1001;
        int x=ret(root,max1);
        return max1;
    }
};