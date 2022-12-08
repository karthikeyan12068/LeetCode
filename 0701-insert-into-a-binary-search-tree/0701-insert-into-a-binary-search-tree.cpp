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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur=root;
        if(root==NULL){
            root=new TreeNode(val);
        }
        else{
            TreeNode* temp=cur;
            while(true){
                if(cur->val>val){
                    temp=cur;
                    cur=cur->left;
                }
                else{
                    temp=cur;
                    cur=cur->right;
                }
                if(cur==NULL){
                    cur=new TreeNode(val);
                    break;
                }
            }
            if(temp->val>val){
                temp->left=new TreeNode(val);
            }
            else{
                temp->right=new TreeNode(val);
            }
        }
        return root;
    }
};