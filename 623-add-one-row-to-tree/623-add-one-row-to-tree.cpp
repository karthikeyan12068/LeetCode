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
TreeNode* ret(TreeNode* root,int val,int d){
    if(root==NULL){
        return NULL;
    }
    d--;
    root->left=ret(root->left,val,d);
    root->right=ret(root->right,val,d);
    if(d==0){
        TreeNode* temp1=root->left;
        TreeNode* temp2=root->right;
        root->left=new TreeNode(val);
        root->right=new TreeNode(val);
        root->left->left=temp1;
        root->right->right=temp2;
    }
    return root;
}
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        d--;
        if(d==0){
            TreeNode* r=new TreeNode(val);
            r->left=root;
            return r;
        }
        ret(root,val,d);
        return root;
    }
};