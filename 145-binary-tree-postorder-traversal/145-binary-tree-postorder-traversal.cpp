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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v1;
        if(root==NULL){
            return v1;
        }
        stack<int>s;
        stack<TreeNode*>stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* cur=stack.top();
            stack.pop();
            s.push(cur->val);
            if(cur->left){
                stack.push(cur->left);
            }
            if(cur->right){
                stack.push(cur->right);
            }
        }
        while(!s.empty()){
            v1.push_back(s.top());
            s.pop();
        }
        return v1;
    }
};