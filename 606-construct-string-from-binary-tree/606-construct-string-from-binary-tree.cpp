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
string s="";
string ret(TreeNode* root){
    if(root==NULL){
        return "";
    }
    if(root->left!=NULL && root->right!=NULL || root->left==NULL && root->right!=NULL){
        s=to_string(root->val)+"("+ret(root->left)+")"+"("+ret(root->right)+")";
    }
    else{
        if(root->left==NULL && root->right==NULL){
            s=to_string(root->val);
            return s;
        }
        if(root->right==NULL){
            s=to_string(root->val)+"("+ret(root->left)+")";
            return s;
        }
    }
    return s;
}
class Solution {
public:
    string tree2str(TreeNode* root) {
        stack<TreeNode*>stack;
        TreeNode* cur=root;
        if(s!=""){
            s="";
        }
        string z=ret(root);
        return s;
    }
};