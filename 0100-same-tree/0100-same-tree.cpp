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
bool preorder(TreeNode* root1,TreeNode* root2){
    if(root1!=NULL && root2==NULL || root1==NULL && root2!=NULL){
        return false;
    }
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1->val!=root2->val){
        return false;
    }
    return true && preorder(root1->left,root2->left) && preorder(root1->right,root2->right);
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorder(p,q);
    }
};