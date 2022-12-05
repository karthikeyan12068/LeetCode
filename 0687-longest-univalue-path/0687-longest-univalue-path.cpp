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
    if(root->left==NULL && root->right==NULL){
        return 0;
    }
    int left=0,right=0;
    if(root->left!=NULL && root->left->val==root->val){
        left=1+ret(root->left,max1);
    }
    else{
        if(root->left!=NULL){
            left=-10000000+ret(root->left,max1);
        }
    }
    if(root->right!=NULL && root->right->val==root->val){
        right=1+ret(root->right,max1);
    }
    else{
        if(root->right!=NULL){
            right=-1000000+ret(root->right,max1);
        }
    }
    max1=max(max(max(left+right,max(left,right)),0),max1);
    cout<<left<<" "<<right<<"\n";
    return max(max(left,right),0);
}
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int max1=-1;
        int z=ret(root,max1);
        return max(0,max1);
    }
};