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

TreeNode* ret(TreeNode* root1,TreeNode* root2){
    if(root1==NULL && root2==NULL){
        return NULL;
    }
    if(root1!=NULL && root2!=NULL){
        root1->val+=root2->val;
    }
    else{
        if(root1==NULL){
            root1=new TreeNode(root2->val);
        }
        if(root2==NULL){
            root2=new TreeNode(root1->val);
        }
    }
    root1->left=ret(root1->left,root2->left);
    root1->right=ret(root1->right,root2->right);
    return root1;
}
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return ret(root1,root2);
        
    }
};