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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v1;
        stack<TreeNode*>stack;
        TreeNode* cur=root;
        while(!stack.empty() || cur!=NULL){
            if(cur!=NULL){
                stack.push(cur);
                cur=cur->left;
            }
            else{
                cur=stack.top();
                stack.pop();
                v1.push_back(cur->val);
                cur=cur->right;
            }
        }
        return v1;
    }
};