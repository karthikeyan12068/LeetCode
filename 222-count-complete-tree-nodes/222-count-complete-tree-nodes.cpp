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
    int countNodes(TreeNode* root) {
        stack<TreeNode*>stack;
        TreeNode* cur=root;
        int c=0;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
               c++; 
                stack.push(cur);
                cur=cur->left;
            }
            else{
                cur=stack.top();
                stack.pop();
                cur=cur->right;
            }
        }
        return c;
    }
};