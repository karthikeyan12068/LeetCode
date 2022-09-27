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
int s=0;
int ret(TreeNode* root){
    if(root==NULL){
        return -1;
    }
    int s1=1+ret(root->left);
    int s2=1+ret(root->right);
    s=max(s,s1+s2);
    return max(s1,s2);
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(s!=0){
            s=0;
        }
        int y=-1;
        y=ret(root);
        return s;
    }
};